#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct edge {
  int v;
  ll w;
  bool operator<(const edge &o) const { return o.w < w; }
};

const int N = 1e5 + 10;
int n, m, b[N];
bitset<N> vis;
priority_queue<edge> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int u, w;
  cin >> n >> m;
  forn(i, 0, m) {
    cin >> u >> w;
    pq.push({u - 1, w});
  }
  forn(i, 0, n) { cin >> b[i]; }
  edge e;
  vis.reset();
  ll mark = 0, ans = 0;
  while (mark < n) {
    e = pq.top();
    pq.pop();
    if (vis[e.v]) continue;
    vis[e.v] = true;
    mark++;
    ans += e.w;
    if (e.v == 0)
      pq.push({n - 1, b[n - 1]});
    else
      pq.push({e.v - 1, b[e.v - 1]});
    if (e.v == n - 1)
      pq.push({0, b[n - 1]});
    else
      pq.push({e.v + 1, b[e.v]});
  }
  cout << ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main g.cpp && ./main < g.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/