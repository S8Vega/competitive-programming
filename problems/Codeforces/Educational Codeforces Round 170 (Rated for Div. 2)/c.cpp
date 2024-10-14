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

void solve() {
  int n, k, mx = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
    mx = max(mx, x);
  }
  map<int, int> rep;
  for (int &x : a) {
    rep[x]++;
  }
  // cout << n << " " << k << endl;
  // for (int i = 1; i <= mx; i++) {
  //   cout << rep[i] << " ";
  // }
  // cout << endl;
  ll ans = 0, cur = 0, sz = 0;
  for (auto x : rep) {
    int i = x.F;
    // if (rep[i] == 0) cur = 0, sz = 0;
    if (rep.find(i - 1) == rep.end()) cur = 0, sz = 0;
    if (sz < k) {
      cur += rep[i];
      sz++;
    } else if (sz == k) {
      cur += rep[i] - rep[max(0, i - k)];
    }
    ans = max(ans, cur);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // dbg(N);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}