#include <bits/stdc++.h>
using namespace std;

int t, c, m, x;

bool f(int q) {
  return min(c, m) >= q && (max(c - q, 0) + max(m - q, 0) + x) >= q;
}

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("b.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int l, r, mt;
  cin >> t;
  while (t--) {
    cin >> c >> m >> x;
    l = 0, r = max(c, m) * 2;
    while (l <= r) {
      mt = (l + r) / 2;
      // cout << l << ' ' << r << ' ' << mt << ' ' << f(mt) << endl;
      if (f(mt))
        l = mt + 1;
      else
        r = mt - 1;
    }
    cout << r << endl;
  }
  return 0;
}