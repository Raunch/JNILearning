LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := minejni
LOCAL_SRC_FILES := minejni.c

include $(BUILD_SHARED_LIBRARY)