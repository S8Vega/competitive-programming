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

bool test(vector<ll>& a, ll x) {
  for (ll v : a) {
    if (__gcd(v, x) == 1) return true;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  forn(i, 0, n) cin >> a[i];
  vector<ll> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                       43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  for (ll p : primes) {
    if (test(a, p)) {
      cout << p << endl;
      return;
    }
  }
  cout << -1 << endl;
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