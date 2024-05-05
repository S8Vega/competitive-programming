#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v.size()))

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << 500 << ' ';
    }
    cout << endl;
  }
  return 0;
}