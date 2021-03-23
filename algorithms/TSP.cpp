const int MAX = 17;
const int inf = 2e9;
int dp[MAX][(1 << MAX)];
int g[MAX][MAX];
int n, m;

int tsp(int cur = n, int mask = 0) {
  int &r = dp[cur][mask];
  if (mask == (1 << n) - 1) return r = 0;
  if (r != inf) return r;
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0 && g[cur][i] >= 0) {
      r = min(r, tsp(i, mask | (1 << i)) + g[cur][i]);
    }
  }
  return r;
}

vector<int> ans;
void build(int cur = n, int mask = 0) {
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0 && g[cur][i] >= 0 &&
        dp[i][mask | (1 << i)] == dp[cur][mask] - g[cur][i]) {
      ans.push_back(i);
      build(i, mask | (1 << i));
      break;
    }
  }
}

void init() {
  memset(g, -1, sizeof(g));
  for (int i = 0; i <= n; i++) {
    g[n][i] = 0;
    for (int j = 0; j <= (1 << n); j++) {
      dp[i][j] = inf;
    }
  }
  ans.clear();
}

int k;
while (cin >> n >> m >> k) {
  init();
  for (int i = 0, u, v, c; i < m; i++) {
    cin >> u >> v >> c;
    g[u][v] = g[v][u] = c;
  }
  cout << tsp(k, 1 << k) << endl;
  build(k, 1 << k);
  for (auto x : ans) cout << x << endl;
}