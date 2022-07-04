#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size <= 1) {
            return size;
        }

        vector<int> candy(size, 1);
        for(int i = 1; i < size; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for(int i = size - 1; i > 0; --i) {
            if(ratings[i] < ratings[i - 1]) {
                candy[i - 1] = max(candy[i - 1], candy[i] + 1);
            }
        }

        int res = 0;
        for(int i = 0; i < size; ++i) {
            res += candy[i];
        }

        return res;
    }
};