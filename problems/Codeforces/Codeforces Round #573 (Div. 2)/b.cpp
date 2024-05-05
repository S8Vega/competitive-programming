#include <bits/stdc++.h>
using namespace std;

int f(string s) {
  int ans = s[0] - '0';
  if (s[1] == 's')
    ans += 20;
  else if (s[1] == 'p')
    ans += 10;
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int n[3];
  string s[3];
  while (cin >> s[0] >> s[1] >> s[2]) {
    n[0] = f(s[0]);
    n[1] = f(s[1]);
    n[2] = f(s[2]);
    sort(n, n + 3);
    // cout << n[0] << ' ' << n[1] << ' ' << n[2] << endl;
    if (n[0] == n[2] || (n[0] == n[1] - 1 && n[1] == n[2] - 1))
      cout << 0 << endl;
    else if ((n[0] == n[1] || n[1] == n[2]) ||
             (n[0] == n[1] - 1 || n[1] == n[2] - 1) ||
             ((n[0] == n[1] - 2 && n[0] != 9) ||
              (n[1] == n[2] - 2 && n[1] != 9)))
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}