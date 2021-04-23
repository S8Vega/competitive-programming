#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v.size()))

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, c;
  string s;
  set<char> st;
  cin >> t;
  while (t--) {
    cin >> s;
    st.clear();
    c = 1;
    for (int i = 1; i < sz(s); i++) {
      if (s[i] == s[i - 1])
        c++;
      else {
        if (c & 1) st.insert(s[i - 1]);
        c = 1;
      }
    }
    if (c & 1) st.insert(s[sz(s) - 1]);
    for (auto x : st) cout << x;
    cout << endl;
  }
  return 0;
}