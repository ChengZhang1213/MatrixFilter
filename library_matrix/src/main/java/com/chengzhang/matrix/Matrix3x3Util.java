package com.chengzhang.matrix;

import android.graphics.Bitmap;

/**
 * Created by ChengZhang on 2016/10/28.
 */

public class Matrix3x3Util {
    static {
        System.loadLibrary("native-lib");
    }


    public static native int[] convolutionBitmap( int[] pixels, int width, int height,double[] matrix, double factor, int offset);
}
