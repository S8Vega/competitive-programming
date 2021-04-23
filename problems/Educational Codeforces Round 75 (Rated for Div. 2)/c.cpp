#include <bits/stdc++.h>
using namespace std;
#define sz(s) ((int)(s.size()))

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
  // freopen("mainout.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t;
  string s;
  queue<char> a, b;
  cin >> t;
  while (t--) {
    cin >> s;
    for (int i = 0; i < sz(s); i++) {
      if ((s[i] - '0') & 1)
        a.push(s[i]);
      else
        b.push(s[i]);
    }
    while (sz(a) || sz(b)) {
      if (sz(a) == 0)
        cout << b.front(), b.pop();
      else if (sz(b) == 0)
        cout << a.front(), a.pop();
      else if (a.front() < b.front())
        cout << a.front(), a.pop();
      else
        cout << b.front(), b.pop();
    }
    cout << endl;
  }
  return 0;
}