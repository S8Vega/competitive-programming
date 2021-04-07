#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
#ifdef LOCAL
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#else
  fastIO;
#endif
  int n;
  cin >> n;
  vector<int> v(n);
  forn(i, n) cin >> v[i];
  sort(all(v));
  int mx = 1e9;
  for (int i = 0; i < n / 2; i++) {
    mx = min(mx, v[i] + v[n - i - 1]);
  }
  cout << mx << endl;
  return 0;
}