#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 3 * 1e5 + 5;
const ll INF = 1e18 + 5;
int n, a[MAX], b[MAX];
ll dp[MAX][3];

ll f(int i, int j) {
  if (i > n) return 0;
  ll &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = INF;
  for (int ii = 0; ii < 3; ii++) {
    if (a[i - 1] + j != a[i] + ii) ans = min(ans, f(i + 1, ii) + b[i] * ii);
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("d.txt", "r", stdin);
  // freopen("d.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }
    a[0] = -1;
    cout << f(1, 0) << endl;
  }
  return 0;
}