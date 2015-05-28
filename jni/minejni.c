#include <string.h>
#include <jni.h>
#include <android/log.h>

#define LOG_TAG "Test"

#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

jstring Java_com_raunch_testjni_MineJni_getTestString(JNIEnv * env, jobject thiz, jstring test) {
	char buf[128];
	const char *str = (*env)->GetStringUTFChars(env, test, NULL);
	if (str == NULL) {
	return NULL; /* OutOfMemoryError already thrown */
	}
	LOGI("String is %s", str);
	(*env)->ReleaseStringUTFChars(env, test, str);
	LOGI("Just go here");
	return (*env)->NewStringUTF(env, "hello world from jni");
}
