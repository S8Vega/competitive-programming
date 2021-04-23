#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v.size()))

const int MAX = 55;
int t, n, k, ans, a[MAX], szi, szp;
bitset<MAX> b;
string s;

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
  // freopen("mainout.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  cin >> t;
  while (t--) {
    cin >> n;
    k = szi = szp = 0;
    for (int i = 0; i < n; i++) {
      cin >> s;
      if (sz(s) & 1)
        szi += sz(s);
      else
        szp += sz(s);
      a[i] = sz(s);
      for (int j = 0; j < sz(s); j++) {
        if (s[j] == '1') k++;
      }
    }
    if (szi == 0 && k & 1)
      cout << n - 1 << endl;
    else
      cout << n << endl;
  }
  return 0;
}