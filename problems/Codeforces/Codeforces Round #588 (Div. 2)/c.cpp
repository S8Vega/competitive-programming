#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int MAX = 10;
int g[MAX][MAX];
int n, m;

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("mainout.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  cin >> n >> m;
  memset(g, false, sizeof(g));
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    g[u][v] = g[v][u] = true;
  }
  if (n < 7) {
    cout << m << endl;
    return 0;
  }
  int ans = 1e5;
  for (int i = 1, j, k, r; i < 7; i++) {
    for (j = i + 1; j <= 7; j++) {
      for (k = 1, r = 0; k <= 7; k++) {
        if (g[i][k] && g[j][k]) r++;
      }
      ans = min(ans, r);
    }
  }
  cout << m - ans << endl;
  return 0;
}