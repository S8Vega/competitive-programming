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
int n, a[N];

void solve() {
  cin >> n;
  forn(i, 0, n) cin >> a[i];
  int ans = 0;
  forn(i, 2, n - 2) {
    if (a[i - 2] < a[i - 1] && a[i - 1] > a[i] && a[i] < a[i + 1] &&
        a[i + 1] > a[i + 2]) {
      ans++;
      a[i] = max(a[i - 1], a[i + 1]);
    }
  }
  forn(i, 1, n - 1) {
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
      ans++;
      a[i] = max(a[i - 1], a[i + 1]);
    }
  }
  cout << ans << endl;
  forn(i, 0, n) cout << a[i] << ' ';
  cout << endl;
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