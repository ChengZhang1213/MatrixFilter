//
// Created by Test-PC on 2016/10/24.
//

#include <string.h>
#include "MatrixFilter.h"
#include "Color.h"
#include "Util.h"

int* MatrixFilter::processImage() {
    int pixR, pixG, pixB, newR, newG, newB, index;

    int maskSize = 3;
    int halfMaskSize = maskSize / 2;

    int *edgePixels = new int[width * height];
    memset(edgePixels, 0, width * height * sizeof(int));
    for (int i = halfMaskSize; i < height - halfMaskSize; i++) {
        for (int k = halfMaskSize; k < width - halfMaskSize; k++) {
            
            index = 0;
            newR = newG = newB = 0;
            for (int m = -halfMaskSize; m <= halfMaskSize; m++) {
                for (int n = -halfMaskSize; n <= halfMaskSize; n++) {
                    int pixel_index = (i + n) * width + k + m;
                    
                    if (pixel_index < width * height) {
                        Color pixColor(pixels[pixel_index]);
                        pixR = pixColor.R();
                        pixG = pixColor.G();
                        pixB = pixColor.B();

                        newR += pixR * kernal[index];
                        newG += pixG * kernal[index];
                        newB += pixB * kernal[index];
                        index++;
                    }
                }
            }

            newR =  min(255, max(0, (int)(newR / factor)+offset ));
            newG =  min(255, max(0, (int)(newG / factor)+offset ));
            newB =  min(255, max(0, (int)(newB / factor)+offset ));

            edgePixels[i * width + k] = RGB2Color(newR, newG, newB);
        }
    }

    for (int i = 0; i < width * height; i++) {
        Color edgeColor(edgePixels[i]);
        int r = min(255, max(0, edgeColor.R()));
        int g = min(255, max(0, edgeColor.G()));
        int b = min(255, max(0, edgeColor.B()));
        pixels[i] = RGB2Color(r, g, b);
    }

    delete[] edgePixels;
    return pixels;
}
