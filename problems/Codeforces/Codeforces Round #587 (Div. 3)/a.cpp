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
  int n, c;
  string s;
  cin >> n >> s;
  c = 0;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i + 1]) s[i] = 'a', s[i + 1] = 'b', c++;
  }
  cout << c << endl << s << endl;
  return 0;
}