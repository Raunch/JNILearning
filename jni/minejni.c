#include <string.h>
#include <jni.h>

jstring Java_com_raunch_testjni_MineJni_getTestString(JNIEnv * env, jobject thiz) {
	return (*env)->NewStringUTF(env, "hello world from jni");
}
