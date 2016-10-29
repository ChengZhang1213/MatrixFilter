//
// Created by Test-PC on 2016/10/21.
//

#ifndef JNITEST_UTIL_H
#define JNITEST_UTIL_H

#include "Color.h"
#include <android/log.h>
#include <jni.h>
#include <stddef.h>
#include <sys/time.h>

#define    LOG_TAG    "ImageHandle"
#define    LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define    LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

//#define	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, FilterClass, options) ({\
//	jint* pixelsBuff = getPixleArray(env, pixels); \
//	FilterClass filter(pixelsBuff, width, height, options); \
//	int *_result = filter.procImage(); \
//	result = jintPointerToJintArray(env, width * height, _result); \
//	releaseArray(env, pixels, pixelsBuff); \
//	result; \
//})\

#define PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, kernal, factor, offset, FilterClass) ({\
    jint* pixelsBuff = getPixleArray(env, pixels); \
    jdouble* kernalBuff = getKernalArray(env, kernal); \
    FilterClass filter(pixelsBuff, width, height, kernalBuff,factor,offset); \
    int *_result = filter.processImage(); \
    result = jintPointerToJintArray(env, width * height, _result); \
    releaseArray(env, pixels, pixelsBuff); \
    result; \
})\


typedef void (*GENERAL_IMG_PROC_FUNC)(int *, int, int); // pixels, width, height

static inline int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

static inline int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

static inline double min(double a, double b) {
    if (a < b) {
        return a;
    }
    return b;
}

static inline double max(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

static inline jint *getPixleArray(JNIEnv *env, jintArray buff) {
    jint *pixelsBuff = env->GetIntArrayElements(buff, 0);
    if (pixelsBuff == NULL) {
        LOGE("can't get pixels");
    }
    return pixelsBuff;
}
static inline jdouble *getKernalArray(JNIEnv *env, jdoubleArray buff) {
    jdouble *kernalBuff = env->GetDoubleArrayElements(buff, 0);
    if (kernalBuff == NULL) {
        LOGE("can't get pixels");
    }
    return kernalBuff;
}

static inline jintArray jintPointerToJintArray(JNIEnv *env, jint size, jint *arr) {
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, arr);

    return result;
}

static inline void releaseArray(JNIEnv *env, jintArray array1, jint *array2) {
    env->ReleaseIntArrayElements(array1, array2, 0);
}

static inline jintArray procImage(JNIEnv *env, jintArray pixels, jint width, jint height,
                                  GENERAL_IMG_PROC_FUNC procFunc) {
    jint *pixelsBuff = getPixleArray(env, pixels);

    if (pixelsBuff == NULL) {
        LOGE("cannot get the pixels");
    }
    procFunc(pixelsBuff, width, height);

    jintArray result = jintPointerToJintArray(env, width * height, pixelsBuff);
    releaseArray(env, pixels, pixelsBuff);

    return result;
}

static inline void changeImageToGray(int *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        Color color(pixels[i]);
        float gray = color.R() * 0.3 + color.G() * 0.59 + color.B() * 0.11;
        pixels[i] = RGB2Color(gray, gray, gray);
    }
}


#endif //JNITEST_UTIL_H
