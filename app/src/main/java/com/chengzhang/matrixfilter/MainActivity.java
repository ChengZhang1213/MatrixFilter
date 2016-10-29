package com.chengzhang.matrixfilter;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.Spinner;

import com.chengzhang.matrix.Matrix;
import com.chengzhang.matrix.Matrix3x3Util;
import com.chengzhang.matrix.MatrixFactory;
import com.chengzhang.matrix.MatrixType;

import java.io.IOException;
import java.io.InputStream;

public class MainActivity extends AppCompatActivity {

    ImageView iv_src;
    ImageView iv_out;
    MatrixFactory matrixFactory;
    Bitmap bitmap;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        matrixFactory = MatrixFactory.getInstance();
        try {
            InputStream open = getApplicationContext().getAssets().open("test.jpg");
            bitmap = BitmapFactory.decodeStream(open);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Spinner sp_filter = (Spinner) findViewById(R.id.sp_filter);

        iv_src = (ImageView) findViewById(R.id.iv_src);
        iv_out = (ImageView) findViewById(R.id.iv_out);
        doConvolution(MatrixType.EMBOSSING);
        sp_filter.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
//                String[] languages = getResources().getStringArray(R.array.filter_type);
                if (position == 0) {
                    doConvolution(MatrixType.EMBOSSING);
                } else if (position == 1) {
                    doConvolution(MatrixType.EDGE_DETECTION);
                } else if (position == 2) {
                    doConvolution(MatrixType.MEAN_REMOVAL);
                } else if (position == 3) {
                    doConvolution(MatrixType.GAUSSIAN_BLUR);
                } else if (position == 4) {
                    doConvolution(MatrixType.SHARPEN);
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
        sp_filter.setSelected(true);

    }



    private void doConvolution(MatrixType matrixType) {

        iv_src.setImageBitmap(bitmap);
        int width = bitmap.getWidth();
        int height = bitmap.getHeight();
        int[] pixels = new int[width * height];
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
        Matrix matrix = matrixFactory.createMatrix(matrixType);
        double[] kernal = matrix.matrix; //Embossing factor = 1,offset = 127
        double factor = matrix.factor;
        int offset = matrix.offset;
        int[] returnPixels = Matrix3x3Util.convolutionBitmap(pixels, width, height, kernal, factor, offset);
        Bitmap returnBitmap = Bitmap.createBitmap(returnPixels, width, height, Bitmap.Config.ARGB_8888);
        iv_out.setImageBitmap(returnBitmap);
    }

}
