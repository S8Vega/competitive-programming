#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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

const int N = 2e3 + 10;
const ll INF = 1e18;
int n;
vector<vector<int>> g;
vector<vector<vector<ll>>> dp;
vector<int> sz;
vector<int> hp;

void dfs(int x) {
  sz[x] = 0;
  vector<vector<ll>> buffer(sz[x] + 1, vector<ll>(2));
  buffer[0][0] = 0;
  buffer[0][1] = INF;
  ll sum = 0;
  for (int u : g[x]) {
    dfs(u);
    sum += hp[u];
    vector<vector<ll>> nbuffer(sz[x] + sz[u] + 1, vector<ll>(2, INF));
    for (int i = 0; i <= sz[u]; ++i) {
      for (int j = 0; j <= sz[x]; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int l = 0; l < 2; ++l) {
            ll v = dp[u][i][k] - (k ? hp[u] : 0);
            nbuffer[i + j][k || l] =
                min(nbuffer[i + j][k || l], v + buffer[j][l]);
          }
        }
      }
    }
    sz[x] += sz[u];
    buffer = nbuffer;
  }
  sz[x]++;
  dp[x].resize(sz[x] + 1, vector<ll>(2, INF));
  for (int m = 0; m <= sz[x]; ++m) {
    if (m < SZ(buffer))
      dp[x][m][0] = min(buffer[m][0], buffer[m][1]) + hp[x] + sum;
    if (m > 0) dp[x][m][1] = buffer[m - 1][0];
  }
  for (int m = 0; m <= sz[x]; ++m) dp[x][m][0] = min(dp[x][m][0], dp[x][m][1]);
}

void solve() {
  cin >> n;
  g = vector<vector<int>>(n);
  dp = vector<vector<vector<ll>>>(n);
  sz = vector<int>(n);
  hp = vector<int>(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    g[p - 1].push_back(i);
  }
  for (int i = 0; i < n; ++i) cin >> hp[i];
  dfs(0);
  for (int i = 0; i <= n; ++i) cout << min(dp[0][i][0], dp[0][i][1]) << " ";
  cout << endl;
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