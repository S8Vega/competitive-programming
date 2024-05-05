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

int f(int ans[]) {
  int res = 0;
  forn(i, 0, 10) {
    if (ans[i] == -1) return -1;
    res += ans[i];
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  int ans[10];
  forn(i, 0, 10) ans[i] = -1;
  forn(i, 0, n) {
    int b, d;
    cin >> b >> d;
    ans[d - 1] = max(ans[d - 1], b);
  }
  int res = f(ans);
  if (res == -1)
    cout << "MOREPROBLEMS" << endl;
  else
    cout << res << endl;
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