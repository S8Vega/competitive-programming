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

const int N = 30;
pii a[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> a[i].F >> a[i].S;
  ll ans = 1ll * n * (n + 1) * m * (m + 1);
  ans /= 4;
  for (int i = 1; i < (1 << k); i++) {
    int cnt = 0, mxx = -1, mxy = -1, mnx = 1e9 + 9, mny = 1e9 + 9;
    for (int j = 0; j < k; j++) {
      if ((i & (1 << j)) == 0) continue;
      mxx = max(mxx, a[j].F);
      mxy = max(mxy, a[j].S);
      mnx = min(mnx, a[j].F);
      mny = min(mny, a[j].S);
      cnt++;
    }
    ll te = 1ll * mnx * mny * (n - mxx + 1) * (m - mxy + 1);
    if (cnt % 2)
      ans -= te;
    else
      ans += te;
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