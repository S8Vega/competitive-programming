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

const int N = 110;
int n, a[N];

void solve() {
  cin >> n;
  forn(i, 0, n) cin >> a[i];
  int ans = 0;
  a[n] = 1e5;
  forn(i, 0, n - 1) {
    int j = n;
    for (int jj = i; jj < n; jj++) {
      if (a[jj] < a[j]) j = jj;
    }
    ans += j - i + 1;
    reverse(a + i, a + j + 1);
  }
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t;
  cin >> t;
  forn(i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main a.cpp -DLOCAL && ./main
*/