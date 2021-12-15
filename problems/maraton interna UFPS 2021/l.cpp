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

const int MX = 1e3 + 10;  // Tamanio maximo de la matriz
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
char grid[MX][MX];  // Matriz de caracteres
bitset<MX> vis[MX];
int ind[MX][MX];  // Indice de la matriz
int n, m;         // Tamanio de la matriz

vector<int> par, sz;
int sizeDsu;

int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }

void unite(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  if (sz[u] > sz[v]) swap(u, v);
  par[u] = v;
  sz[v] += sz[u];
  sizeDsu--;
}

int count(int u) { return sz[find(u)]; }

int floodfill(int y, int x) {
  int cnt = 0;
  queue<pii> q;
  q.push({y, x});
  vis[y][x] = 1;
  while (!q.empty()) {
    int cy = q.front().F, cx = q.front().S;
    q.pop();
    cnt++;
    // dbg(cy, cx);
    forn(i, 0, 4) {
      int ny = cy + dy[i], nx = cx + dx[i];
      // dbg(ny, nx);
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (vis[ny][nx]) continue;
      // dbg("aca", grid[ny][nx]);
      if (grid[ny][nx] == '#') continue;
      // dbg(ind[ny][nx], ind[cy][cx]);
      unite(ind[ny][nx], ind[cy][cx]);
      vis[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
  return cnt;
}

void solve() {
  cin >> n >> m;
  forn(i, 0, m) { forn(j, 0, n) cin >> grid[j][i]; }

  int aux = 0;
  forn(i, 0, n) {
    forn(j, 0, m) ind[i][j] = aux++;
    vis[i].reset();
  }
  par = vector<int>(n * m + 10);
  iota(par.begin(), par.end(), 0);
  sizeDsu = n * m + 10;
  sz = vector<int>(n * m + 10, 1);

  // forn(i, 0, n) {
  //   forn(j, 0, m) { cout << grid[j][i] << ' '; }
  //   cout << endl;
  // }

  int q;
  cin >> q;
  forn(i, 0, q) {
    int x, y;
    cin >> x >> y;
    if (!vis[y - 1][x - 1]) floodfill(y - 1, x - 1);
    cout << count(ind[y - 1][x - 1]) << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int caso = 1;
  int t;
  cin >> t;
  while (t--) {
    cout << "Case " << caso++ << ":" << endl;
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