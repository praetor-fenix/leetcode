#define MAXN 40

class Solution {
private:
    int arr[MAXN];

public:
    Solution() {
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2; i < MAXN; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }

    int fib(int n) {
        return arr[n];
    }
};