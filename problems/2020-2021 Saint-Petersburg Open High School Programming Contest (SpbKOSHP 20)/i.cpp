#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... E>
void debug(T t, E... e) {
  cout << t << (sizeof...(e) ? " " : "");
  debug(e...);
}
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define SZ(v) ((int)(v.size()))
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
vector<int> g[N];
int ind[N];
bitset<N> vis;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  forn(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    g[u].pb(v);
    g[v].pb(u);
    if (!u) {
      vis[v] = 1;
    }
  }
  forn(u, 0, n) {
    if (!vis[u]) continue;
    for (int &v : g[u]) {
      ind[v]++;
    }
  }
  ll ans = 0;
  forn(i, 1, n) {
    if (ind[i] >= 2) ans += 1ll * ind[i] * (ind[i] - 1);
  }
  cout << ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main i.cpp && for x in i*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/