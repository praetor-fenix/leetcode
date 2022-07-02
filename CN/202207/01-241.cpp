#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(string &expr, int begin, int end, vector<int> &v) {
        for(int i = begin; i < end; ++i) {
            char ch = expr[i];
            if(ch == '+' || ch == '-' || ch == '*') {
                vector<int> lv, rv;
                dfs(expr, begin, i, lv);
                dfs(expr, i + 1, end, rv);
                for(auto lt = lv.begin(); lt != lv.end(); ++lt) {
                    for(auto rt = rv.begin(); rt != rv.end(); ++rt) {
                        int left = *lt, right = *rt;
                        if(ch == '+') {
                            v.push_back(left + right);
                        } else if(ch == '-') {
                            v.push_back(left - right);
                        } else {
                            v.push_back(left * right);
                        }
                    }
                }
            }
        }

        if(v.empty()) {
            int n = 0;
            for(int i = begin; i < end; ++i) {
                n = n * 10 + (expr[i] - '0');
            }
            v.push_back(n);
        }
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        dfs(expression, 0, expression.length(), res);
        return res;
    }
};