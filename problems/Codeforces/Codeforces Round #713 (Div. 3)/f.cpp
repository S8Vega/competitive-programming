#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 2e5 + 10;
const ll MAX = 1e12;
ll n, c, a[N], b[N];

ll binary_search(ll cur_c, int i, ll x) {
  ll l = 0, r = MAX, m;
  while (l <= r) {
    m = (l + r) / 2;
    if (cur_c + a[i] * m >= x)
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}

void solve() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  ll mx = 0, cur = 0, cnt = 0, ans = 1e15;
  for (ll i = 0; i < n; i++) {
    mx = max(mx, a[i]);
    ll cost = max(0LL, (c - cnt + mx - 1) / mx);
    ans = min(ans, cost + cur);
    if (i < n - 1) {
      cost = max(0LL, (b[i] - cnt + mx - 1) / mx);
      cnt += cost * mx - b[i];
      cur += 1 + cost;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}