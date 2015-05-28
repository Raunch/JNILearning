LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := minejni
LOCAL_SRC_FILES := minejni.c

LOCAL_LDLIBS   := -llog

include $(BUILD_SHARED_LIBRARY)