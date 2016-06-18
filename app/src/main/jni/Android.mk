LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := NdkSampleApp
LOCAL_SRC_FILES := NdkSampleApp.cpp
include $(BUILD_SHARED_LIBRARY)
