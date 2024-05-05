#include <bits/stdc++.h>
using namespace std;

int m = 11;
char c[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

bool f(string &s) {
  int n = s.size();
  bool r;
  for (int i = 0; i <= n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
    r = false;
    for (int j = 0; j < m && !r; j++) {
      r = s[i] == c[j];
    }
    if (!r) return false;
  }
  return true;
}

int main() {
#ifdef LOCAL
  freopen("h.txt", "r", stdin);
  // freopen("h.out", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    if (f(s))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
