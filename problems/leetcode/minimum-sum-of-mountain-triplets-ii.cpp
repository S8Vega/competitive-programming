class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);
        l[0] = nums[0];
        for (int i = 1; i < n; i++) {
            l[i] = min(l[i - 1], nums[i]);
        }
        r[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = min(r[i + 1], nums[i]);
        }
        int INF = 1e9 + 7;
        int ans = INF;
        for (int i = 1; i < n - 1; i++) {
            if (l[i - 1] < nums[i] && nums[i] > r[i + 1])
                ans = min(ans, l[i - 1] + nums[i] + r[i + 1]);
        }
        return (ans == INF ? -1 : ans);
    }
};
static const int FAST__ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();