class Solution {
public:
    long long smallestNumber(long long num) {
        int digits[10];
        long long numCopy = num;
        while (numCopy != 0) {
            digits[abs(numCopy % 10)]++;
            numCopy /= 10;
        }
        long long ans = 0;
        if (num > 0) {
            for (int i = 1; i < 10; i++) {
                while (digits[i]--) {
                    ans = ans * 10 + i;
                    while (digits[0]-- > 0)
                        ans = ans * 10;
                }
            }
        } else {
            for (int i = 9; i >= 0; i--) {
                while (digits[i]--)
                    ans = ans * 10 + i;
            }
            ans = -ans;
        }
        return ans;
    }
};