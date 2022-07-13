#include <cmath>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i = 0; i < asteroids.size(); ++i) {
            int aster = asteroids[i];
            bool alive = true;
            while(alive && aster < 0 && !res.empty() && res.back() > 0) {
                alive = res.back() < -aster;
                if(res.back() <= -aster) {
                    res.pop_back();
                }
            }
            if(alive) {
                res.push_back(aster);
            }
        }
        return res;
    }
};
