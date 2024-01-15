class Solution {
 public:
  unordered_map<int, unordered_map<int, double>> dp;

  double f(int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1;
    if (b <= 0) return 0;
    if (dp[a].count(b)) return dp[a][b];
    return dp[a][b] = (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) +
                       f(a - 1, b - 3)) /
                      4;
  }

  double soupServings(int n) {
    n = ceil(n / 25.0);
    for (int i = 1; i <= n; i++) {
      if (f(i, i) > 1 - 1e-5) return 1;
    }
    return f(n, n);
  }
};