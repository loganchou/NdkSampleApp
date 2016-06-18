//
// Created by logan on 2016/06/18.
//

#include <stdio.h>
#include "com_logan_dev_ndksampleapp_NdkSampleApp.h"


JNIEXPORT jstring JNICALL Java_com_logan_dev_ndksampleapp_NdkSampleApp_getString
        (JNIEnv *env, jclass cls, jstring url) {

    const char *c_url = NULL;

    c_url = env->GetStringUTFChars(url, NULL);
    if (c_url == NULL) {
        return env->NewStringUTF("url is null string!!"); // memory out
    }
    printf("c_str: %s\n", (char *) c_url);
    env->ReleaseStringUTFChars(url, c_url);

    return env->NewStringUTF(c_url);
}