#include <bits/stdc++.h>
using namespace std;
#define sz(s) ((int)(s.size()))
#define ll long long

int n, mx;

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    mx = 1;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) {
        mx = max(mx, i);
        mx = max(mx, n / i);
      }
    cout << mx << ' ' << (n - mx) << endl;
  }
  return 0;
}