//
// Created by logan on 2016/06/18.
//

#include <stdio.h>
#include <stdlib.h>

#include <android/log.h>
#include "com_logan_dev_ndksampleapp_NdkSampleApp.h"

#define LOG_TAG "jni.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

template<typename T>
void swap(T *a, T *b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Class:     com_logan_dev_ndksampleapp_NdkSampleApp
 * Method:    getHtml
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_logan_dev_ndksampleapp_NdkSampleApp_getHtml
        (JNIEnv *env, jclass cls, jstring url) {

    const char *c_url = NULL;

    c_url = env->GetStringUTFChars(url, NULL);
    if (c_url == NULL) {
        return env->NewStringUTF("url is null string!!"); // memory out
    }
    printf("c_str: %s\n", (char *) c_url);
    LOGD("url = %d", 111);

    env->ReleaseStringUTFChars(url, c_url);

    char *catString;
    catString = (char*) malloc(sizeof(char) * (strlen(c_url) + 3));
    sprintf(catString, "{%s}", c_url);

    jstring ret = env->NewStringUTF(catString);
    free(catString);
    return ret;
}

/*
 * Class:     com_logan_dev_ndksampleapp_NdkSampleApp
 * Method:    invertBooleans
 * Signature: ([Z)[Z
 */
JNIEXPORT jbooleanArray JNICALL Java_com_logan_dev_ndksampleapp_NdkSampleApp_invertBooleans
  (JNIEnv *env, jclass cls, jbooleanArray values) {

    LOGD("invertBooleans↓↓↓↓↓↓↓↓↓↓start↓↓↓↓↓↓↓↓↓↓");

    jsize len = env->GetArrayLength(values);
    jboolean* elems = env->GetBooleanArrayElements(values, NULL);

    for (int i = 0; i < len; i++) {
        LOGD("input value[%d] = %s\n", i, (elems[i]==JNI_TRUE ? "true" : "false"));

        if (elems[i] == JNI_TRUE)
            elems[i] = JNI_FALSE;
        else
            elems[i] = JNI_TRUE;

        LOGD( "output value[%d] = %s\n", i, (elems[i]==JNI_TRUE ? "true" : "false") );
    }

    env->ReleaseBooleanArrayElements(values, elems, 0);

    LOGD("invertBooleans↑↑↑↑↑↑↑↑↑↑end↑↑↑↑↑↑↑↑↑↑");

    return values;
}

/*
 * Class:     com_logan_dev_ndksampleapp_NdkSampleApp
 * Method:    sortBytes
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_logan_dev_ndksampleapp_NdkSampleApp_sortBytes
  (JNIEnv *env, jclass cls, jbyteArray values) {

    LOGD("sortBytes↓↓↓↓↓↓↓↓↓↓start↓↓↓↓↓↓↓↓↓↓");

    jsize len = env->GetArrayLength(values);
    jbyte* elems =env->GetByteArrayElements(values, 0);

    int i, j;
    LOGD("input values :");
    for (i = 0; i < len; i++)
        LOGD("[%d] -> ", elems[i]);
    LOGD("end.");

    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (elems[j] > elems[j + 1])
                swap(&elems[j], &elems[j + 1]);

    LOGD("output values :");
    for (i = 0; i < len; i++)
        LOGD("[%d] -> ", elems[i]);
    LOGD("end.");

    env->ReleaseByteArrayElements(values, elems, 0);

    LOGD("sortBytes↑↑↑↑↑↑↑↑↑↑end↑↑↑↑↑↑↑↑↑↑");

    return values;
}

/*
 * Class:     com_logan_dev_ndksampleapp_NdkSampleApp
 * Method:    concatCharsToString
 * Signature: ([C)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_logan_dev_ndksampleapp_NdkSampleApp_concatCharsToString
  (JNIEnv *env, jclass cls, jcharArray values) {

}

/*
 * Class:     com_logan_dev_ndksampleapp_NdkSampleApp
 * Method:    sortInts
 * Signature: ([I)I
 */
JNIEXPORT jintArray JNICALL Java_com_logan_dev_ndksampleapp_NdkSampleApp_sortInts
  (JNIEnv *env, jclass cls, jintArray values) {

    jint* pCIntArr;
    jsize len;

    len = env->GetArrayLength(values);
    pCIntArr = (jint*) malloc(sizeof(jint) * len);
    if (pCIntArr == NULL)
        return NULL;

    memset(pCIntArr, 0, sizeof(jint) * len);

    env->GetIntArrayRegion(values, 0, len, pCIntArr);

    int i, j;
    LOGD("input values :");
    for (i = 0; i < len; i++)
        LOGD("[%d] -> ", *(pCIntArr + i));
    LOGD("end.");

    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (pCIntArr[j] > pCIntArr[j + 1])
                swap(&pCIntArr[j], &pCIntArr[j + 1]);

    LOGD("output values :");
    for (i = 0; i < len; i++)
        LOGD("[%d] -> ", pCIntArr[i]);
    LOGD("end.");

    jintArray ret = env->NewIntArray(len);
    jint* elems =env->GetIntArrayElements(ret, 0);
    for (i = 0; i < len; i++)
        elems[i] = pCIntArr[i];
    env->ReleaseIntArrayElements(ret, elems, 0);
    free(pCIntArr);

    return ret;
}
