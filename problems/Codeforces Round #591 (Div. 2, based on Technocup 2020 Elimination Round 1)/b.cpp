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
  bool ans;
  int t;
  string s1, s2;
  int c[30];
  cin >> t;
  while (t--) {
    memset(c, 0, sizeof(c));
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
      c[s1[i] - 'a']++;
    }
    ans = false;
    for (int i = 0; i < s2.size() && !ans; i++) {
      if (c[s2[i] - 'a'] > 0) ans = true;
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}