#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("b.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, n, ans, m;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    while (n--) {
      cin >> m;
      if (m <= 2048) ans += m;
    }
    if (ans >= 2048)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}