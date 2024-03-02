class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> d(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    if (d[i] < d[j] + 1) {
                        d[i] = d[j] + 1;
                        cnt[i] = 0;
                    }
                    if (d[j] + 1 == d[i])
                        cnt[i] += cnt[j];
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ' << d[i] << ' ' << cnt[i] << endl;
        int maxLength = *max_element(d.begin(), d.end());
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (d[i] == maxLength) {
                result += cnt[i];
            }
        }

        return result;
    }
};