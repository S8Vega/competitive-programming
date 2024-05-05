#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
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

const int N = 2e5 + 10;
int n, q[N];

void solve() {
  cin >> n;
  vector<int> v[2];
  set<int> st[2];
  forn(i, 1, n + 1) st[0].insert(i), st[1].insert(n - i);
  forn(i, 0, n) {
    cin >> q[i];
    if (i) {
      if (q[i] != q[i - 1]) {
        st[0].erase(st[0].find(q[i]));
        st[1].erase(st[1].find(n - q[i]));
      }
    } else {
      st[0].erase(st[0].find(q[i]));
      st[1].erase(st[1].find(n - q[i]));
    }
  }
  forn(i, 0, n) {
    if (i) {
      if (q[i] != q[i - 1]) {
        v[0].pb(q[i]);
      } else {
        int mn = *st[0].begin();
        v[0].pb(mn);
        st[0].erase(st[0].find(mn));
      }
    } else {
      v[0].pb(q[i]);
    }
  }
  v[1].resize(n);
  for (int i = 0; i < n; i++) {
    if (i) {
      if (q[i] != q[i - 1]) {
        v[1][i] = q[i];
      } else {
        auto mx = st[1].upper_bound(n - q[i]);
        v[1][i] = n - *mx;
        st[1].erase(mx);
      }
    } else {
      v[1][i] = q[i];
    }
  }

  forn(i, 0, 2) {
    forn(j, 0, n) cout << v[i][j] << ' ';
    cout << endl;
  }
}

int main() {
#ifdef LOCAL
  freopen("e.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main e.cpp -DLOCAL && ./main
*/