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

ll n;
map<ll, int> dp;

void init() {
  ll ant = 0, cur;
  forn(i, 1, 10) {
    cur = i;
    forn(j, 0, 9) {
      dp[cur]++;
      cur = cur * 10 + i;
    }
  }
  for (auto x : dp) {
    // dbg(x.F, x.S);
    if (ant) {
      dp[x.F] = x.S + dp[ant];
    }
    ant = x.F;
  }
}

void solve() {
  cin >> n;
  int ind = 0;
  for (auto x : dp) {
    if (x.F <= n)
      ind++;
    else
      break;
  }
  cout << ind << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
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