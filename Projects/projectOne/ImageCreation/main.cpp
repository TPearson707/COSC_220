/*
 * Name of Author: Thomas Pearson
 * Date of Creation: 10/16/2023
 * Date of Last Update: 10/16/2023
 * Description: main that utilizes the bitmap_image library and complex numbers class to create bitmap images
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Complex.h"
#include "bitmap_image.hpp"

using namespace std;

int main() {

    unsigned size;
    string filename;
    unsigned maxiter;
    double cr, ci, borderRatio, colorExponent, bailout;

    cout << "Input the image size (in pixels): ";
    cin >> size;

    cout << "Input the real value of c: ";
    cin >> cr;

    cout << "Input the imaginary value of c: ";
    cin >> ci;

    cout << "Input the maximum iteration (100 - 1000): ";
    cin >> maxiter;

    cout << "Input the border ratio (0 - 1): ";
    cin >> borderRatio;

    cout << "Input the color exponent (0 - 1): ";
    cin >> colorExponent;

    cout << "Input the bailout redius (>= 4): ";
    cin >> bailout;

    cout << "Input the output file name (no spaces or extension): ";
    cin >> filename;

    bitmap_image pic(size, size);
    pic.clear();

    Complex c(cr, ci);
    Complex z;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            double zr = ((static_cast<double>(4) * x) / size) - 2;
            double zi = ((static_cast<double>(4) * y) / size) - 2;

            z.set(zr, zi);

            int col;
            unsigned n = 0;

            while(n < maxiter) {
                z = (z^2) + c;

                if (z.mod() > bailout) {
                    col = 0;

                    if (n > (maxiter * borderRatio)) {
                        col = 255;
                    } else if (n != maxiter) {
                        col = pow((static_cast<double>(n) / maxiter), colorExponent) * 255;
                    }

                   // cout << col;
                    pic.set_pixel(x, y, col, col, col);

                    n = maxiter;
                }

                n++;

            }
        }
    }

    pic.save_image(filename + ".bmp");

    return 0;
}
