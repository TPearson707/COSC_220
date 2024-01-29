/*
 * Name: Thomas Pearson
 * Date of Creation: 9/26/2023
 * Date of Last Update: 9/26/2023
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

class Array2D {
private:
    int** A = nullptr;
    int rows;
    int cols;

public:
    Array2D(int r = 3, int c = 3, int defval = 0);
    ~Array2D();

    void display();
    void display(int);
    int getRows();
    int getCols();
    void resize(int r = 3, int c = 3, int defval = 0);
    void set(int, int, int);
    int get(int, int);
};

# endif //ARRAY2D_H
