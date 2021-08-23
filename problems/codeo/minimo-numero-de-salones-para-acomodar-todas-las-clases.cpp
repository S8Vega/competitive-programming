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

const int N = 24 * 70;
int n, rango[N];

void solve() {
  cin >> n;
  char c;
  int h[2], m[2];
  while (n--) {
    cin >> h[0] >> c >> m[0] >> h[1] >> c >> m[1];
    // cout << h[0] << c << m[0] << ' ' << h[1] << c << m[1] << endl;
    int l = h[0] * 60 + m[0], r = h[1] * 60 + m[1];
    rango[l]++, rango[r]--;
  }
  forn(i, 1, N) rango[i] += rango[i - 1];
  int mx = 0;
  forn(i, 0, N) mx = max(mx, rango[i]);
  cout << mx << endl;
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