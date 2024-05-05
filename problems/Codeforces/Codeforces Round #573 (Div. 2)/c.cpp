#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int i, d, j;
  ll n, m, k, p, ans;
  cin >> n >> m >> k;
  ll a[m];
  for (i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  for (i = 0, d = 0, ans = 0; i < m;) {
    p = ((a[i] - d - 1) / k) * k;
    j = i;
    while (j < m && a[j] - d <= p + k) j++;
    d += j - i;
    i = j;
    ans++;
  }
  cout << ans << endl;
  return 0;
}