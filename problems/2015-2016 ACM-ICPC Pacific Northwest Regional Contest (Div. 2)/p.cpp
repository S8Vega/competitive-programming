#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define sz(s) ((int)(s.size()))

int main() {
#ifdef LOCAL
  freopen("p.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int a[26];
  memset(a, 0, sizeof(a));
  string s;
  cin >> s;
  for (int i = 0; i < sz(s); i++) {
    a[s[i] - 'a']++;
  }
  sort(a, a + 26);
  int ans = 0;
  for (int i = 0; i < 24; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
