#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <unistd.h>
#include <sys/types.h>

#define LOG_TAG "Test"

#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

jstring Java_com_raunch_testjni_MineJni_getTestString(JNIEnv * env, jobject thiz, jstring test) {
	char buf[128];
	const char *str = (*env)->GetStringUTFChars(env, test, NULL);
	if (str == NULL) {
	return NULL; /* OutOfMemoryError already thrown */
	}
	char outbuf[128];
	int length = (*env)->GetStringLength(env, test);
	(*env)->GetStringUTFRegion(env, test, 0, length-1, outbuf);
	LOGI("sub string is %s ", outbuf);
	LOGI("String is %s", str);
	(*env)->ReleaseStringUTFChars(env, test, str);
	LOGI("Just go here");
	return (*env)->NewStringUTF(env, "hello world from jni");
}

jint Java_com_raunch_testjni_MineJni_sumArray(JNIEnv *env, jobject thiz, jintArray arr) {
	jint *buf;
	jint i;
	jint sum=0;
	//(*env)->GetIntArrayRegion(env, arr, 0, 10, buf);
	buf = (*env)->GetIntArrayElements(env, arr, NULL);
	    if (buf == NULL) {
	        return 0; /* exception occurred */
	    }
	for(i=0; i<10; i++) {
		sum = sum + buf[i];
	}
	(*env)->ReleaseIntArrayElements(env, arr, buf, 0);
	return sum;
}

jobjectArray Java_com_raunch_testjni_MineJni_initInt2DArray(JNIEnv *env,  jclass cls, jint size) {
	jobjectArray *result;
	int i;
	jclass intArrCls = (*env)->FindClass(env, "[I");
	if (intArrCls == NULL) {
		return NULL;
	}
	result = (*env)->NewObjectArray(env, 3, intArrCls, NULL);
	if (result == NULL) {
		return NULL;
	}
	for(i=0; i<size; i++) {
		int tmp[256];
		int j;
		jintArray iarr = (*env)->NewIntArray(env, size);
		if (iarr == NULL) {
			return NULL;
		}
		for(j=0; j<size; j++) {
			tmp[j] = i + j;
		}
		(*env)->SetIntArrayRegion(env, iarr, 0, size, tmp);
		(*env)->SetObjectArrayElement(env, result, i, iarr);
		(*env)->DeleteLocalRef(env, iarr);
	}
	return result;
}

void Java_com_raunch_testjni_MineJni_accessField(JNIEnv *env, jobject thiz) {
	jfieldID fid, fid2;
	jstring jstr;
	jint jworld;
	const char *str;
	int world;

	jclass cls = (*env)->GetObjectClass(env, thiz);
	LOGI("In C level");
	fid = (*env)->GetFieldID(env, cls, "mHello", "Ljava/lang/String;");
	fid2 = (*env)->GetStaticFieldID(env, cls, "mWorld", "I");
	if (fid == NULL || fid2 == NULL) {
		return;
	}
	jstr = (*env)->GetObjectField(env, thiz, fid);
	str = (*env)->GetStringUTFChars(env, jstr, NULL);
	if (str == NULL) {
		return;
	}
	jworld = (*env)->GetStaticIntField(env, cls, fid2);
	world = jworld;
	(*env)->ReleaseStringUTFChars(env, jstr, str);
	jstr = (*env)->NewStringUTF(env, "Fuck you OK");
	if (jstr == NULL) {
		return;
	}
	(*env)->SetObjectField(env, thiz, fid, jstr);
	(*env)->SetStaticIntField(env, cls, fid2, 200);
}

void getPackageName(JNIEnv *env, int pid) {
	jclass vmstack = (*env)->FindClass(env, "dalvik/system/VMStack");
	if (vmstack == NULL) {
		LOGI("No find hide class");
	}
	jmethodID getCallingClassLoader = (*env)->GetStaticMethodID(env, vmstack, "getCallingClassLoader", "()Ljava/lang/ClassLoader;" );
	if (getCallingClassLoader == NULL) {
		LOGI("No find method getDefault");
	} else {
		jobject i_am = (*env)->CallStaticObjectMethod(env, vmstack, getCallingClassLoader);
		if(i_am == NULL) {
			LOGI("i_am null");
		}
	}
	LOGI("fucking here");
}

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	//int MAX_SIZE = 512;
	LOGI("Just go here, gaga");
	//char current_absolute_path[MAX_SIZE];
	//getcwd(current_absolute_path, MAX_SIZE);
	//LOGI("Current path is %s", current_absolute_path);
	pid_t pid = getpid();
	LOGI("Current pid is %d", pid);

	JNIEnv* env = NULL;
	jint result = -1;
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return -1;
	}
	result = JNI_VERSION_1_4;
	getPackageName(env, pid);

	return result;
}
