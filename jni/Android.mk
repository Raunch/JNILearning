LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := minejni
LOCAL_SRC_FILES := minejni.c

LOCAL_LDLIBS   := -llog -lc

LOCAL_SHARED_LIBRARIES := libnativehelper

 LOCAL_C_INCLUDES += $(JNI_H_INCLUDE)

include $(BUILD_SHARED_LIBRARY)