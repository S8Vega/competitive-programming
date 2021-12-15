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

const int MAX = 600;
char g[MAX][MAX];
int dist[MAX][MAX];
int n, m;
int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};
int endX, endY;
string path[MAX][MAX];
string letters = "URLD";

void init() {
  forn(i, 0, n) forn(j, 0, m) {
    dist[i][j] = -1;
    path[i][j] = "";
  }
}

void bfs(int y, int x) {
  queue<pii> q;
  q.push({y, x});
  dist[y][x] = 0;
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    y = p.F, x = p.S;
    // dbg(x, y);
    forn(i, 0, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      // dbg(nx, ny);
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if (dist[ny][nx] != -1 || g[ny][nx] == '#') continue;
      dist[ny][nx] = dist[y][x] + 1;
      // dbg(letters[i], dist[ny][nx]);
      g[ny][nx] = letters[i];
      path[ny][nx] = path[y][x] + letters[i];
      q.push({ny, nx});
    }
  }
}

void solve() {
  cin >> n >> m;
  init();
  int sx, sy, ex, ey;
  forn(i, 0, n) {
    forn(j, 0, m) {
      cin >> g[i][j];
      if (g[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (g[i][j] == 'X') {
        ex = i;
        ey = j;
      }
    }
  }
  bfs(sx, sy);

  // forn(i, 0, n) {
  //   forn(j, 0, m) cout << dist[i][j] << ' ';
  //   cout << endl;
  // }
  // forn(i, 0, n) {
  //   forn(j, 0, m) cout << g[i][j] << ' ';
  //   cout << endl;
  // }

  if (dist[ex][ey] == -1) {
    cout << "No exit" << endl;
  } else {
    cout << path[ex][ey] << endl;
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