#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define pii pair<int, int>
#define y first
#define x second

const int MAX = 510;
int m, n, g[MAX][MAX], d[MAX][MAX];

bool valid(int i, int j) { return i >= 0 && j >= 0 && i <= m && j <= n; }

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void bfs(int y, int x) {
  queue<pii> q;
  q.push({y, x});
  d[y][x] = 0;
  pii u;
  while (q.size()) {
    u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      y = u.y + dy[i] * g[u.y][u.x];
      x = u.x + dx[i] * g[u.y][u.x];
      if (valid(y, x) && d[y][x] == -1) {
        d[y][x] = d[u.y][u.x] + 1;
        q.push({y, x});
      }
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("o.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  cin >> m >> n;
  string s;
  for (int i = 0; i < m; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      g[i][j] = s[j] - '0';
    }
  }
  memset(d, -1, sizeof(d));
  bfs(0, 0);
  if (d[m - 1][n - 1] == -1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << d[m - 1][n - 1] << endl;
  return 0;
}
