#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3) {
            return false;
        }

        bool dp[l2 + 1];
        for(int t1 = 0; t1 <= l1; ++t1) {
            for(int t2 = 0; t2 <= l2; ++t2) {
                dp[t2] = 
                    (t1 == 0 && t2 == 0) 
                    || (t1 > 0 && dp[t2] && s1[t1 - 1] == s3[t1 + t2 - 1]) 
                    || (t2 > 0 && dp[t2 - 1] && s2[t2 - 1] == s3[t1 + t2 - 1]);
            }
        }

        return dp[l2];
    }
};