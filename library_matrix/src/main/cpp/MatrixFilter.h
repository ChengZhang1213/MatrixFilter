//
// Created by Test-PC on 2016/10/24.
//

#ifndef JNITEST_MATRIXFILTER_H
#define JNITEST_MATRIXFILTER_H


#include <math.h>

class MatrixFilter {
private:
    int *pixels;//the array of bitmap pixels;
    int width;//the bitmap width
    int height;//the bitmap height
    double *kernal;
    double factor;
    int offset;
public:

    MatrixFilter(int *pixels, int width, int height, double *kernal, double factor, int offset) :
            pixels(pixels), width(width), height(height), kernal(kernal),
            factor(factor), offset(offset) { }

    int *processImage();
};


#endif //JNITEST_MATRIXFILTER_H
