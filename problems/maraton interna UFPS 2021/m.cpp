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

const int MX = 1e3 + 5;
vector<int> g[MX];
bitset<MX> vis;

void init(int n) {
  forn(i, 0, n + 1) g[i].clear();
  vis.reset();
}

void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) dfs(v);
}

void solve() {
  int n, m;
  cin >> n >> m;
  init(n);
  forn(i, 0, m) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int ans = 0;
  forn(i, 0, n) {
    if (!vis[i]) {
      dfs(i);
      ++ans;
    }
  }
  if (ans == 1) {
    cout << "Pure Compound!" << endl;
  } else {
    cout << "Mixture: " << ans << endl;
  }
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
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/