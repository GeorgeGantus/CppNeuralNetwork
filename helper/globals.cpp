
#include <math.h>
float meanSquaredError(float y, float yHat) {
    return pow(yHat - y, 2) / 2;
}
float meanSquaredErrorDerivative(float y, float yHat) {
    return y - yHat;
}
float sigmoid(float x) {
    return 1 / (1 + exp(-1 * x));
}
float sigmoidDerivative(float x) {
    return sigmoid(x) * (1 - sigmoid(x));
}