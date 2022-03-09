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

const ll N = 2e9;
vector<ll> ans;
set<ll> set_ans;

void solve() {
  int n;
  cin >> n;
  int l = 0, r = SZ(ans) - 1, m;
  // forn(i, 0, 30) cout << ans[i] << ' ';
  // cout << endl;
  while (l < r) {
    m = (l + r) / 2;
    // dbg(l, r, m, ans[m]);
    if (ans[m] > n)
      r = m;
    else
      l = m + 1;
  }
  cout << r << endl;
}

void init() {
  for (ll i = 1; i * i < N; ++i) {
    if (i * i < N) set_ans.insert(i * i);
    if (i * i * i < N) set_ans.insert(i * i * i);
  }
  for (auto x : set_ans) ans.pb(x);
  dbg(SZ(ans));
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
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/