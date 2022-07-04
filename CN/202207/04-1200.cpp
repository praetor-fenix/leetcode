#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i = 1; i < arr.size(); ++i) {
            diff = min(diff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> res;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] - arr[i - 1] == diff) {
                vector<int> pair {
                    arr[i - 1], arr[i]
                };
                res.push_back(pair);
            }
        }

        return res;
    }
};