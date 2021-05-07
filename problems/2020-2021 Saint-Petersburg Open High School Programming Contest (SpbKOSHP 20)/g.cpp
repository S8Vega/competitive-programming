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
#define SZ(v) ((int)(v.size()))
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 10;
int n, v, u, a[N];

bool f(double d) {
  double t = d / u;
  double c = t * v;
  double ans = 0;
  forn(i, 0, n) { ans += max(0.0, a[i] - c); }
  return ans <= d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> v >> u;
  forn(i, 0, n) cin >> a[i];
  double l = 0, r = 1e15, m;
  forn(i, 0, 100) {
    m = (l + r) / 2;
    if (f(m))
      r = m;
    else
      l = m;
  }
  cout << fixed << setprecision(7) << l << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main g.cpp && for x in g*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/