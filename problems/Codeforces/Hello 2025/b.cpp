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
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> rep;
  forn(i, 0, n) {
    cin >> a[i];
    rep[a[i]]++;
  }
  ans = SZ(rep);
  vector<int> rep_ord;
  for (auto x : rep) {
    rep_ord.pb(x.S);
  }
  sort(rep_ord.begin(), rep_ord.end());
  for (int i = 0; i < SZ(rep_ord); i++) {
    if (rep_ord[i] <= k) {
      ans--;
      k -= rep_ord[i];
    } else {
      break;
    }
  }
  cout << max(ans, 1) << endl;
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