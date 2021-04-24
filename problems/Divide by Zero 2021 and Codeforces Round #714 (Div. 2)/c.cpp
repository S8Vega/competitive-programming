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

const int MAX = 2e5 + 100;
const ll mod = 1e9 + 7;
vector<vector<ll>> dp(MAX, vector<ll>(10, 0));

void init() {
  dp[0][0] = 1;
  for (ll i = 0; i <= MAX - 50; i++) {
    for (ll j = 0; j <= 8; j++) {
      dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j + 1] %= mod;
    }
    dp[i + 1][0] += dp[i][9];
    dp[i + 1][0] %= mod;
    dp[i + 1][1] += dp[i][9];
    dp[i + 1][1] %= mod;
  }
}

void solve() {
  ll m;
  string n;
  cin >> n >> m;
  ll ans = 0;
  for (ll i = 0; i < SZ(n); i++) {
    for (ll j = 0; j < 10; j++) {
      ans += dp[m + n[i] - '0'][j];
      ans %= mod;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}