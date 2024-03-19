class Solution {
public:
    static const int MOD = 12345;

    static int mul(int x, int y) { return (x % MOD) * (y % MOD) % MOD; }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n);
        int pre = 1, suf = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre = mul(pre, grid[i][j]);
                prefix[i].push_back(pre);
            }
        }
        int tmp;
        for(int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                tmp = suf;
                suf = mul(suf, grid[i][j]);
                if (i == 0 && j == 0) pre = 1;
                else if (j == 0) pre = prefix[i - 1][m - 1];
                else pre = prefix[i][j - 1];
                grid[i][j] = mul(tmp, pre);
            }
        }
        return grid;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
