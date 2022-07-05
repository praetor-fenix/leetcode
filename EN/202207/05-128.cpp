#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(map.count(n) > 0) {
                continue;
            }
            int left = map.count(n - 1) > 0 ? map[n - 1] : 0;
            int right = map.count(n + 1) > 0 ? map[n + 1] : 0;
            int sum = left + right + 1;
            map[n] = sum;
            res = max(res, sum);
            map[n - left] = sum;
            map[n + right] = sum;
        }

        return res;
    }
};