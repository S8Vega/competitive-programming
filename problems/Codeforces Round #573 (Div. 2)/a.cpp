#include <bits/stdc++.h>
using namespace std;

char rk[] = {'D', 'A', 'C', 'B'};

char f(int n) { return rk[(n % 4)]; }

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  char ans;
  int n, mx;
  while (cin >> n) {
    ans = 'E';
    mx = 0;
    for (int i = 2; i >= 0; i--) {
      ans = min(ans, f(n + i));
      mx = ans == f(n + i) ? i : mx;
    }
    cout << mx << ' ' << ans << endl;
  }
  return 0;
}