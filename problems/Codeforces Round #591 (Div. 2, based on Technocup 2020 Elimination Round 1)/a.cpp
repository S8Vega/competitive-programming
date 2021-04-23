#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n < 4)
      cout << 4 - n << endl;
    else if (n & 1)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}