#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... E>
void debug(T t, E... e) {
  cout << t << (sizeof...(e) ? " " : "");
  debug(e...);
}
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

struct pll {
  int id;
  ll F, S;
};

const int N = 1e5 + 10;
int n;
pll a[2][N], o1, o2;
bitset<N> vis[2];

ll dist(pll x, pll y) { return abs(x.F - y.F) + abs(x.S - y.S); }

bool cmp1(pll &x, pll &y) { return dist(o1, x) < dist(o1, y); }

bool cmp2(pll &x, pll &y) { return dist(o2, x) < dist(o2, y); }

bool f(ll d) {
  int c[2];
  forn(i, 0, 2) {
    vis[i].reset();
    forn(j, 0, n) {
      if (dist(a[i][0], a[i][j]) >= d || dist(a[i][n - 1], a[i][j]) >= d) {
        vis[i][a[i][j].id] = 1;
      }
    }
    c[i] = vis[i].count();
  }
  if (c[0] == n || c[1] == n) return true;
  bool ans = false;
  forn(i, 0, n) {
    if (!vis[0][i] && !vis[1][i]) return false;
    if (vis[0][i] && vis[1][i]) ans = true;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  o1.F = 0, o1.S = 0;
  o2.F = 0, o2.S = 3e9;
  forn(i, 0, n) {
    a[0][i].id = i;
    cin >> a[0][i].F >> a[0][i].S;
    a[1][i] = a[0][i];
  }
  sort(a[0], a[0] + n, cmp1);
  sort(a[1], a[1] + n, cmp2);
  // forn (i, 0, 30) debug(i, f(i));
  ll l = 1, r = 2e9 + 1, m;
  while (l < r) {
    m = (l + r) / 2;
    if (f(m))
      l = m + 1;
    else
      r = m;
  }
  cout << l - 1 << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main b.cpp && ./main < b.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/