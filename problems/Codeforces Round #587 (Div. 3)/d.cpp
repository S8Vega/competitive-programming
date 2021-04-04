#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("d.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int n;
  ll y, z, mx;
  cin >> n;
  vector<ll> v(n);
  y = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    y = max(y, v[i]);
  }
  z = 0;
  for (int i = 0; i < n; i++) {
    v[i] = (y - v[i]);
    z = __gcd(z, v[i]);
  }
  y = 0;
  for (int i = 0; i < n; i++) {
    if (v[i]) v[i] = (v[i] / z);
    // cout << v[i] << ' ';
    y += v[i];
  }
  cout << y << ' ' << z << endl;
  return 0;
}