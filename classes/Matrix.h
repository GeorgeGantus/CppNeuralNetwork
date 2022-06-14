#pragma once
class Matrix {
   private:
    int width;
    int height;

   public:
    Matrix(int height = 1, int width = 1);
    ~Matrix();
    int getHeight();
    int getWidth();
    void print();
    void randomize();
    void scalarMultiplication(float value);
    Matrix matricialMultiplication(Matrix m);
    Matrix operator+(Matrix m);
    Matrix operator-(Matrix m);
    Matrix operator*(float val);
    Matrix operator*(Matrix m);
    Matrix applyFunc(float (*func)(float));
    float **data;
};