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

const int N = 2e5 + 10;
int n, a[N], ps[2][N];
ll ans[3];

void solve() {
  cin >> n;
  vector<int> zeros;
  forn(i, 0, n) {
    cin >> a[i];
    if (a[i] == 0) zeros.pb(i);
  }
  int ind;
  forn(i, 0, n) {
    ind = lower_bound(zeros.begin(), zeros.end(), i) - zeros.begin();
    if (ind == SZ(zeros)) continue;
    ans[1] += n - zeros[ind];
  }
  ind = ps[0][n] = ps[1][n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      ps[0][i] = ps[1][i] = ind = 0;
      continue;
    }
    ps[ind][i] = ps[ind][i + 1] + 1;
    ps[!ind][i] = ps[!ind][i + 1];
    if (a[i] < 0) ind = !ind;
  }
  // forn(i, 0, 2) {
  //   forn(j, 0, n) cout << ps[i][j] << ' ';
  //   cout << endl;
  // }
  ind = 1;
  for (int i = n - 1; i >= 0; i--) {
    // dbg(i, ind);
    if (a[i] < 0) ind = !ind;
    ans[0] += ps[ind][i];
    if (a[i] == 0) ind = 1;
  }
  ans[2] = 1ll * n * (n + 1) / 2 - ans[0] - ans[1];
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
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