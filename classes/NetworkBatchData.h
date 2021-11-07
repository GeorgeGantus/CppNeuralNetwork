#include <vector>

class NetworkBatchData {
   private:
    vector<vector<float>> _layersResults;
    vector<vector<float>> _weightedInputs;
    vector<vector<float>> _summedDelta;
    /* data */
   public:
    NetworkBatchData();
    void resetCurrent();
    void resetBatch();
    void saveCurrentLayerResult(vector<float> a);
    void saveCurrentLayerWeightedInput(vector<float> a);
    void computeDelta(float y);
};