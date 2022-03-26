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

typedef ld T;

struct pt {
  T x, y;
};

T cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

const int N = 2510;
ld dp[N][N];
pt puntos[N];

void f(int n) {
  dp[0][0] = 1;
  forn(i, 1, n + 1) {
    dp[i][0] = 1;
    forn(j, 1, i + 1) { dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]; }
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  f(n);
  forn(i, 1, n + 1) cin >> puntos[i].x >> puntos[i].y;
  ld ans = 0;
  int x;
  forn(i, 1, n + 1) {
    forn(j, k - 1, n) {
      x = (i + j);
      if (x > n) x -= n;
      ans += cross(puntos[i], puntos[x]) * dp[j - 1][k - 2] / dp[n][k];
    }
  }
  cout << fixed << setprecision(10) << ans / 2 << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
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