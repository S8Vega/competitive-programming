#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
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

const int N = 8005;
int n, a[N], c[N];
ll dp[N];

void solve() {
  cin >> n;
  ll total = 0;
  forn(i, 0, n) cin >> a[i];
  forn(i, 0, n) {
    cin >> c[i];
    total += c[i];
  }
  ll best = 0;
  forn(i, 0, n) {
    dp[i] = c[i];
    forn(j, 0, i) {
      if (a[j] <= a[i]) {
        dp[i] = max(dp[i], dp[j] + c[i]);
      }
    }
    best = max(best, dp[i]);
  }

  cout << total - best << endl;
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