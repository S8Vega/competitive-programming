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

const int N = 1e3 + 10;
bool odd_cycle;
ll n, x[N], y[N], r[N], mark[N];
vector<int> g[N];

bool connect(int u, int v) {
  ll dist = (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]);
  return dist == (r[u] + r[v]) * (r[u] + r[v]);
}

void dfs(int u = 0) {
  for (int &v : g[u]) {
    if (mark[v]) {
      if (mark[v] == mark[u]) {
        odd_cycle = true;
        return;
      }
    } else {
      mark[v] = -mark[u];
      dfs(v);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (connect(i, j)) {
        g[i].pb(j);
        g[j].pb(i);
      }
    }
  }
  odd_cycle = false;
  memset(mark, 0, sizeof mark);
  mark[0] = 1;
  dfs();
  if (odd_cycle) {
    cout << "The input gear cannot move." << endl;
  } else if (!mark[n - 1]) {
    cout << "The input gear is not connected to the output gear." << endl;
  } else {
    if (mark[0] != mark[n - 1]) cout << '-';
    ll gcd = __gcd(r[0], r[n - 1]);
    cout << r[0] / gcd << ':' << r[n - 1] / gcd << endl;
  }
}

int main() {
#ifdef LOCAL
  freopen("v.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  solve();
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main v.cpp -DLOCAL && ./main
*/