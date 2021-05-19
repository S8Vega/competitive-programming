#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v.size()))
#define ll long long

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  ll t, n, m, x, parn, parm;
  cin >> t;
  while (t--) {
    cin >> n;
    parn = parm = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x % 2 == 0) parn++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> x;
      if (x % 2 == 0) parm++;
    }
    cout << (parn * parm) + ((n - parn) * (m - parm)) << endl;
  }
  return 0;
}