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

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  map<char, int> count;
  for (char c : s) {
    count[c]++;
  }
  // for (auto x : count) dbg(x.F, x.S);
  int total = 0;
  map<char, bool> vis;
  for (auto x : count) {
    if (vis[x.F]) continue;
    vis[(char)tolower(x.F)] = true;
    total += min(count[(char)tolower(x.F)], count[(char)toupper(x.F)]);
    total +=
        min(abs(count[(char)tolower(x.F)] - count[(char)toupper(x.F)]) / 2, k);
    k -= min(abs(count[(char)tolower(x.F)] - count[(char)toupper(x.F)]) / 2, k);
    // dbg(x.F, x.S, count[(char)tolower(x.F)], count[(char)toupper(x.F)],
    // total,
    //     k);
  }

  cout << total << endl;
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