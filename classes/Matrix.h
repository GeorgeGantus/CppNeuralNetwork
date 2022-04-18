
class Matrix {
   private:
    int width;
    int height;

   public:
    Matrix(int width, int height);
    ~Matrix();
    int getHeight();
    int getWidth();
    void print();
    void scalarMultiplication(float value);
    Matrix matricialMultiplication(Matrix m);
    Matrix operator+(Matrix m);
    Matrix operator*(float val);
    Matrix operator*(Matrix m);
    float **data;
};