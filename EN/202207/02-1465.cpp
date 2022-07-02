#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int mh = horizontalCuts[0];
        int mw = verticalCuts[0];
        
        for(int i = 1; i < horizontalCuts.size(); ++i) {
            mh = max(mh, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        for(int i = 1; i < verticalCuts.size(); ++i) {
            mw = max(mw, verticalCuts[i] - verticalCuts[i - 1]);
        }

        mh = max(mh, h - horizontalCuts[horizontalCuts.size() - 1]);
        mw = max(mw, w - verticalCuts[verticalCuts.size() - 1]);

        return (int)(((long long)mh * (long long)mw) % 1000000007);
    }
};