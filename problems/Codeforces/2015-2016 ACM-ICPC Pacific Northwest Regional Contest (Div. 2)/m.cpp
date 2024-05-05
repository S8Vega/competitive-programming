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
  vector<pair<string, int>> v(n);
  forn(i, n) cin >> v[i].F >> v[i].S;
  int ans = 0;
  for (ll i = 1; i <= 100; i++) {
    ll cur = i;
    forn(j, n) {
      if (v[j].F == "ADD") {
        cur += v[j].S;
        continue;
      } else if (v[j].F == "SUBTRACT" && cur - v[j].S >= 0) {
        cur -= v[j].S;
        continue;
      } else if (v[j].F == "MULTIPLY") {
        cur *= v[j].S;
        continue;
      } else if (v[j].S != 0 && v[j].F == "DIVIDE" && cur % v[j].S == 0) {
        cur /= v[j].S;
        continue;
      } else {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}