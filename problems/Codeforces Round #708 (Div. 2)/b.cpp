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

int n, m;
map<int, int> rep;

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t, x, y, ans, j;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    rep.clear();
    forn(i, 0, n) {
      cin >> x;
      rep[x % m]++;
    }
    if (m == 1) {
      cout << 1 << endl;
      continue;
    }
    ans = 0;
    forn(i, 0, m) {
      j = m - i;
      if (j == m) j = 0;
      if (j < i) break;
      if (rep[i] == 0 && rep[j] == 0) continue;
      if (j == i) {
        ++ans;
        continue;
      }
      x = rep[i], y = rep[j];
      if (x > y) swap(x, y);
      ++ans;
      y = max(0, y - x - 1);
      ans += y;
    }
    cout << ans << endl;
  }
  return 0;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/