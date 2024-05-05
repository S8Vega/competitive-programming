#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld PI = acos(-1);
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ld L, A;
    cin >> L >> A;
    ld tot = PI * L * L * 0.5;
    ld teta = (A * PI) / 180.0;
    ld area =
        (cos(teta / 2) * L * (sqrt(2 * L * L - 2 * L * L * cos(teta)))) / 2;
    ld rest = (PI * L * L) / (360.0 / (180.0 - A));
    ld ans = tot - area - rest;
    cout << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}
