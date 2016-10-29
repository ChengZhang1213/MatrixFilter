package com.chengzhang.matrix;

/**
 * Created by ChengZhang on 2016/10/24.
 * Matrix 的domain;
 * int matrix[] = {0, -1, 0, -1, 4, -1, 0, -1, 0}; //Embossing factor = 1,offset = 127
 * int matrix[] = {1, 1, 1, 0, 0, 0, -1, -1, -1}; //Edge Detection factor = 1,offset = 127
 * int matrix[] = {-1, -1, -1, -1, 9, -1, -1, -1, -1}; // Mean Removal factor = 1,offset = 0
 * int matrix[] = {1, 2,1, 2, 4, 2, 1, 2, 1}; // Gaussian Blur factor = 16,offset = 0
 * int matrix[] = {0, -2, 0, -2, 11, -2, 0, -2, 0}; //   Sharpen factor = 3,offset = 0;
 * int matrix[] = {0, 1, 0, 1, -4, 1, 0, 1, 0}; //   factor = 1,offset =127;
 */

public class Matrix {
    public double[] matrix;
    public double factor;
    public int offset;

    public Matrix(double[] matrix, double factor, int offset) {
        this.matrix = matrix;
        this.factor = factor;
        this.offset = offset;
    }
}
