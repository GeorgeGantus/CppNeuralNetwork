#include "NetworkBatchData.h"

#include <math.h>

#include <iostream>
#include <vector>

#include "../helper/globals.h"
using namespace std;

void NetworkBatchData::saveCurrentLayerResult(vector<float> a) {
    _layersResults.push_back(a);
}
void NetworkBatchData::resetCurrent() {
    _layersResults.clear();
}
void NetworkBatchData::computeDelta(float y, vector<Layer> layers) {
    vector<vector<float>> delta;
    float lastDelta = meanSquaredErrorDerivative(y, _layersResults.back()[0]) * sigmoidDerivative(_weightedInputs.back()[0]);  //need improvement to accept more then one output
}

vector<vector<float>> matrixMultiplication(vector<vector<float>> a, vector<vector<float>> b) {
    if (a[0].size() != b.size()) {
        cout << "ERROR: invalid matrix sizes";
        return a;
    }
    vector<vector<float>> matrix;
    for (int i = 0; i < a.size(); i++) {
        vector<float> line;
        for (int k = 0; k < b[0].size(); k++) {
            float sum = 0;
            for (int j = 0; j < b.size(); j++) {
                sum += a[i][j] * b[j][k];
            } /* code */
            line.push_back(sum);
        }
        matrix.push_back(line);
    }
    return matrix;
}

vector<vector<float>> transpose(vector<vector<float>> a) {
    vector<vector<float>> matrix;
    for (int i = 0; i < a[0].size(); i++) {
        vector<float> line;
        for (int j = 0; j < a.size(); j++) {
            line.push_back(a[j][i]);
        }
        matrix.push_back(line);
    }
    return matrix;
}
