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

const int N = 35, K = 6000, INF = 1e9;
int n, c[N], e[N], dp[N][K];

int f(int i, int k) {
  if (k < 0) return -INF;
  if (i == n) return 0;
  int &ans = dp[i][k];
  if (ans != -1) return ans;
  ans = max(f(i + 1, k), f(i + 1, k - e[i]) + c[i]);
  return ans;
}

void solve() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) cin >> e[i];
  memset(dp, -1, sizeof(dp));
  cout << f(0, k * 1024) << endl;
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