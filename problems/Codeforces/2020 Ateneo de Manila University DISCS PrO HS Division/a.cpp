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
  string s;
  cin >> s;
  int n = SZ(s);
  int mx = 0, cur = 0, sum = 0;
  vector<int> tam;
  // dbg(s);
  forn(i, 0, n) {
    if (s[i] == '.') {
      sum++;
      cur++;
    } else if (cur > 0) {
      tam.pb(cur);
      cur = 0;
    }
    // dbg(i, cur);
  }
  if (s.back() == '.') tam.pb(cur);
  if (s.back() == '.' && s.front() == '.') tam.pb(tam.back() + tam.front());
  for (int x : tam) {
    // dbg(x);
    mx = max(mx, x);
  }
  // dbg(sum, mx);
  if (sum < mx)
    cout << 0 << endl;
  else
    cout << sum - mx << endl;
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