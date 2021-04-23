#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
ll n, s;
pll e[N];

bool f(ll x) {
  ll sum = 0;
  for (int i = 0; i < n; i++) sum += e[i].F;
  int cnt = 0;
  for (ll i = n - 1; i >= 0 && cnt < (n + 1) / 2; i--) {
    if (e[i].S >= x) {
      sum += max(0ll, x - e[i].F);
      cnt++;
    }
  }
  return sum <= s && cnt == (n + 1) / 2;
}

void solve() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> e[i].F >> e[i].S;
  sort(e, e + n);
  ll l = 1, r = 1e9 + 1, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (f(m))
      l = m;
    else
      r = m;
  }
  cout << l << endl;
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