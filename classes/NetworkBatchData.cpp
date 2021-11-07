#include "NetworkBatchData.h"

#include <math.h>

#include <vector>
using namespace std;
void NetworkBatchData::saveCurrentLayerResult(vector<float> a) {
    _layersResults.push_back(a);
}
void NetworkBatchData::resetCurrent() {
    _layersResults.clear();
}
void NetworkBatchData::computeDelta(float y) {
    vector<vector<float>> delta;
    float lastDelta = meanSquaredErrorDerivative(y, _layersResults.back()[0]) * sigmoidDerivative(_weightedInputs.back()[0]);  //need improvement to accept more then one output
}

float meanSquaredError(float y, float yHat) {
    return pow(y - yHat, 2) / 2;
}
float meanSquaredErrorDerivative(float y, float yHat) {
    return yHat - y;
}
float sigmoid(float x) {
    return 1 / (1 + exp(-1 * x));
}
float sigmoidDerivative(float x) {
    return sigmoid(x) * (1 - sigmoid(x));
}
