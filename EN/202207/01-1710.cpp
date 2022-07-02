#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });

        int res = 0;
        int size = boxTypes.size();
        for(int i = 0; i < size && truckSize > 0; ++i) {
            int load = min(truckSize, boxTypes[i][0]);
            res += load * boxTypes[i][1];
            truckSize -= load;
        }

        return res;
    }
};