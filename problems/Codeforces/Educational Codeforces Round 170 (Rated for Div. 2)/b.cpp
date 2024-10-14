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
// #define endl '\n'
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const ll M = 1e9 + 7;
const int N = 1e1 + 5;
ll C[N][N];

ll ncr(ll n, ll r) {
  if (r < 0 || n < r) return 0;
  r = min(r, n - r);
  ll ans = 1;
  for (int i = 1; i <= r; i++) {
    ans = ans * (n - i + 1) / i;
  }
  return ans;
}

int expmod(int b, int e, int m) {
  int ans = 1;
  while (e) {
    if (e & 1) ans = (1ll * ans * b) % m;
    b = (1ll * b * b) % m;
    e /= 2;
  }
  return ans;
}

void f() {
  for (int n = 0; n < N; n++) {  // loop over n from 0 to N-1 (inclusive)
    C[n][0] = 1;
    C[n][n] = 1;
    for (int k = 1; k < n; k++)  // loop over k from 1 to n-1 (inclusive)
      C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
  }
  // forn(i, 0, N) {
  //   forn(j, 0, N) { cout << C[i][j] << " "; }
  //   cout << endl;
  // }
}

void solve() {
  int t;
  cin >> t;
  vector<int> a(t), b(t);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  forn(i, 0, t) {
    int x = a[i], y = b[i];
    if (x <= y)
      cout << 0 << endl;
    else
      cout << expmod(2, y, M) << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  f();
  solve();
  return 0;
}