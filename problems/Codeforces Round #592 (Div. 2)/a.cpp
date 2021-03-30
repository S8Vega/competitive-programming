#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, a, b, c, d, k;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> k;
    a = (a + c - 1) / c, b = (b + d - 1) / d;
    if (a + b <= k)
      cout << a << ' ' << b << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}