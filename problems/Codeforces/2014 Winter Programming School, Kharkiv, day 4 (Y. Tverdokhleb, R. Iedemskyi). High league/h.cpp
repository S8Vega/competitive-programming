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

const int N = 60;
const ll M = 1e9 + 7;
ll fac[N], inv[N + 1];

ll mulmod(ll a, ll b, ll m = M) {
  ll r = a * b - (ll)((long double)a * b / m + .5) * m;
  return r < 0 ? r + m : r;
}

void invmod() {
  inv[1] = 1;
  for (int i = 2; i <= N; i++) inv[i] = M - (M / i) * inv[M % i] % M;
}

ll ncr(ll n, ll r) {
  if (r < 0 || n < r) return 0;
  r = min(r, n - r);
  ll ans = 1;
  for (int i = 1; i <= r; i++) {
    ans = mulmod(ans, mulmod(n - i + 1, inv[i]));
  }
  return ans;
}

void solve() {
  ll n, p;
  cin >> n >> p;
  // dbg(fac[n], ncr(p - 1, n));
  cout << mulmod(fac[n], ncr(p - 1, n)) << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  invmod();
  fac[0] = 1;
  forn(i, 1, N) fac[i] = mulmod(i, fac[i - 1]);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/