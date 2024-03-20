class Solution {
public:
    bool isPowerOfThree(int n) {
        long long p = 1;
        while (p < n) {
            p *= 3;
        }
        return p == n;
    }
};