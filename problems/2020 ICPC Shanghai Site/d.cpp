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

const double EPS = 1e-8;
double n, p1, v1, p2, v2;

double f1(double m) { return min(p1 + m, 2 * m - p1) / v1; }

double f2(double m) { return min(2 * n - p2 - m, p2 + n - 2 * m) / v2; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> p1 >> v1 >> p2 >> v2;
    if (p1 > p2) {
      swap(p1, p2);
      swap(v1, v2);
    }
    double ans = min(f1(n), min(p2 + n, 2 * n - p2) / v2);
    ans = min(ans, max((n - p1) / v1, p2 / v2));
    double l = p1, r = p2, m, r1, r2;
    forn(i, 0, 80) {
      m = (l + r) / 2;
      r1 = f1(m);
      r2 = f2(m);
      if (r1 < r2)
        l = m;
      else
        r = m;
    }
    ans = min(ans, max(r1, r2));
    cout << fixed << setprecision(10) << ans << endl;
  }
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp && ./main < d.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/
