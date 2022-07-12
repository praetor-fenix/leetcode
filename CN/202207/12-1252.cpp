#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        bool row[m], col[n];
        for(int i = 0; i < m; ++i) {
            row[i] = false;
        }
        for(int i = 0; i < n; ++i) {
            col[i] = false;
        }

        for(int i = 0; i < indices.size(); ++i) {
            int r = indices[i][0];
            int c = indices[i][1];
            row[r] = !row[r];
            col[c] = !col[c];
        }

        int odd_row = 0;
        for(int i = 0; i < m; ++i) {
            odd_row += row[i] ? 1 : 0;
        }

        int res = 0;
        for(int i = 0; i < n; ++i) {
            res += col[i] ? (m - odd_row) : odd_row;
        }

        return res;
    }
};