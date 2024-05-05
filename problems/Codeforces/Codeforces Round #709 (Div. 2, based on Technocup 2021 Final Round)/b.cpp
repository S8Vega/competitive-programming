#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 1e5 + 10;
int n, a[N];

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    forn(i, 0, n) cin >> a[i];
    bool ok = 1;
    int zs = -1, fs = 1;
    forn(i, 1, n) {
      int tmp = a[i] - a[i - 1];
      if (tmp >= 0) {
        if (zs == -1)
          zs = max(zs, tmp);
        else if (zs != tmp)
          ok = 0;
      }
      if (tmp <= 0) {
        if (fs == 1)
          fs = min(fs, tmp);
        else if (fs != tmp)
          ok = 0;
      }
    }

    if (!ok)
      cout << -1 << endl;
    else {
      if (!zs || zs == -1 || fs == 1)
        cout << 0 << endl;
      else {
        int m = zs - fs;
        forn(i, 0, n) if (a[i] >= m) ok = 0;

        if (ok)
          cout << m << ' ' << zs << endl;
        else
          cout << -1 << endl;
      }
    }
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/