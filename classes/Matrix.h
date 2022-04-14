
class Matrix {
   private:
    int width;
    int height;

   public:
    Matrix(int width, int height);
    int getHeight();
    int getWidth();
    void print();
    void scalarMultiplication(float value);
    Matrix matricialMultiplication(Matrix m);

    float **data;
};