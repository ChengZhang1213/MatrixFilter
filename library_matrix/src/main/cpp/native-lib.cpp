#include <jni.h>
#include <string>
#include "Util.h"
#include "MatrixFilter.h"

extern "C" {
jintArray
Java_com_chengzhang_matrix_Matrix3x3Util_convolutionBitmap(JNIEnv *env, jclass type,
                                                           jintArray pixels,
                                                           jint width, jint height,
                                                           jdoubleArray kernal,
                                                           jdouble factor, jint offset) {
    jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, kernal, factor,
                                                  offset, MatrixFilter);
    return result;
}
}
