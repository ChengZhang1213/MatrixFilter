package com.chengzhang.matrix;

/**
 * Created by ChengZhang on 2016/10/24.
 */

public class MatrixFactory {
    private static MatrixFactory instance;

    private MatrixFactory() {

    }

    public synchronized static MatrixFactory getInstance() {
        if (instance == null) {
            instance = new MatrixFactory();
        }
        return instance;
    }

    public Matrix createMatrix(MatrixType flag) {
        Matrix matrix = null;
        double[] kernal;
        switch (flag) {
            case EMBOSSING:
                kernal = new double[]{0, -1, 0, -1, 4, -1, 0, -1, 0};
                matrix = new Matrix(kernal, 1, 127);
                break;
            case EDGE_DETECTION:
                kernal = new double[]{1, 1, 1, 0, 0, 0, -1, -1, -1};
                matrix = new Matrix(kernal, 1, 127);
                break;
            case MEAN_REMOVAL:
                kernal = new double[]{-1, -1, -1, -1, 9, -1, -1, -1, -1};
                matrix = new Matrix(kernal, 1, 0);
                break;
            case GAUSSIAN_BLUR:
                kernal = new double[]{1, 2, 1, 2, 4, 2, 1, 2, 1};
                matrix = new Matrix(kernal, 16, 0);
                break;
            case AVERAGE_BLUR:
                kernal = new double[]{0, 1, 0, 1, 0, 1, 0, 1, 0};
                matrix = new Matrix(kernal, 5, 0);
                break;
            case SHARPEN:
                kernal = new double[]{0, -2, 0, -2, 11, -2, 0, -2, 0};
                matrix = new Matrix(kernal, 3, 0);
                break;
        }
        return matrix;
    }
}
