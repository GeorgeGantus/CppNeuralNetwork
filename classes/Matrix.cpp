#include "Matrix.h"

#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

Matrix::Matrix(int width, int height) {
    this->width = width;
    this->height = height;
    float **data = new float *[height];

    for (int i = 0; i < height; i++) {
        float *line = new float[width]{};
        data[i] = line;
    }

    this->data = data;
}

Matrix::~Matrix() {
    for (int i = 0; i < height; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix Matrix::operator+(Matrix m) {
    if (m.width != width | m.height != height) {
        throw std::invalid_argument("matrices must have compatible sizes");
    }
    Matrix sum = Matrix(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sum.data[i][j] = m.data[i][j] + data[i][j];
        }
    }
    return sum;
}
Matrix Matrix::operator*(float val) {
    Matrix mult = Matrix(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mult.data[i][j] = data[i][j] * val;
        }
    }
    return mult;
}

Matrix Matrix::operator*(Matrix m) {
    if (m.width != width | m.height != height) {
        throw std::invalid_argument("matrices must have compatible sizes");
    }
    Matrix mult = Matrix(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mult.data[i][j] = m.data[i][j] * data[i][j];
        }
    }
    return mult;
}

int Matrix::getHeight() {
    return height;
}

int Matrix::getWidth() {
    return width;
}

void Matrix::print() {
    cout << endl;
    cout << setprecision(2) << fixed;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << data[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::scalarMultiplication(float value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] = value * data[i][j];
        }
    }
}

Matrix Matrix::matricialMultiplication(Matrix m) {
    if (this->width != m.getHeight()) {
        throw std::invalid_argument("matrices must have compatible sizes");
    }
    Matrix result(m.getWidth(), this->height);
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < m.getWidth(); j++) {
            float sumOfTerms = 0;
            for (int k = 0; k < this->width; k++) {
                sumOfTerms += this->data[i][k] * m.data[k][j];
            }
            result.data[i][j] = sumOfTerms;
        }
    }
    return result;
}