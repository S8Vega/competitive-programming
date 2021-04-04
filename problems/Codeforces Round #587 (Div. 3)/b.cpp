#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second
#define ll long long

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
  // freopen("b.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int n;
  cin >> n;
  vector<pii> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].f, v[i].s = i + 1;
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (v[i].f * i + 1);
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << v[i].s;
    if (i + 1 == n)
      cout << endl;
    else
      cout << ' ';
  }
  return 0;
}