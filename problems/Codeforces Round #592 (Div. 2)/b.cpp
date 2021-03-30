#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
  // freopen("mainout.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, n, r, l;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    r = l = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && l == -1) l = i;
      if (s[i] == '1') r = i;
    }
    if (r == -1)
      cout << n << endl;
    else
      cout << max((r + 1) * 2, (n - l) * 2) << endl;
  }
  return 0;
}