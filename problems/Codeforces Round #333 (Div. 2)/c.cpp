#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 405, INF = 1e9;
int n, m, x, y;
int g[N][N], g1[N][N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) g[i][j] = g[j][i] = g1[i][j] = g1[j][i] = INF;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    g[x][y] = g[y][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (g[i][j] == INF) {
        g1[i][j] = g1[j][i] = 1;
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
      }
    }
  }
  if (g[1][n] == INF || g1[1][n] == INF)
    cout << -1 << endl;
  else
    cout << max(g[1][n], g1[1][n]) << endl;
}

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/