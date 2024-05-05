#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(v) ((int)(v.size()))

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  ll n, x, y, r, z;
  vector<ll> v;
  cin >> n;
  x = y = 0;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (i < n / 2 || (n % 2 == 0 && i < n / 2))
      x += v[i];
    else
      y += v[i];
  }
  cout << (x * x) + (y * y) << endl;

  return 0;
}