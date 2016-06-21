LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := NdkSampleApp
LOCAL_SRC_FILES := NdkSampleApp.cpp

# add log lib
LOCAL_LDLIBS:=-llog

include $(BUILD_SHARED_LIBRARY)
