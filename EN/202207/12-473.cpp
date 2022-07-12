#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() <= 0) {
            return false;
        }

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        int sum = 0;
        for(int i = 0; i < matchsticks.size(); ++i) {
            sum += matchsticks[i];
        }

        if(sum % 4 != 0) {
            return false;
        }

        vector<int> side(4, sum / 4);
        return dfs(0, side, matchsticks);
    }

    bool dfs(int idx, vector<int> &side, vector<int> &ms) {
        if(idx >= ms.size()) {
            return true;
        }

        for(int i = 0; i < side.size(); ++i) {
            if(side[i] >= ms[idx]) {
                side[i] -= ms[idx];
                if(dfs(idx + 1, side, ms)) {
                    return true;
                }
                side[i] += ms[idx];
            }
        }

        return false;
    }
};