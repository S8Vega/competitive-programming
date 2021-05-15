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

void f(int n, string& a, string& b, char c) {
  string s = "";
  int i = 0, j = 0;
  while (i < n && j < n) {
    if (a[i] != c)
      s.pb(a[i++]);
    else if (b[j] != c)
      s.pb(b[j++]);
    else
      s.pb(a[i++]), ++j;
  }
  while (i < n) s.pb(a[i++]);
  while (j < n) s.pb(b[j++]);
  cout << s << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<int> z[2];
  string s[3];
  for (int i = 0; i < 3; ++i) {
    cin >> s[i];
    int bal = 0;
    for (char& c : s[i]) bal += (c == '1' ? 1 : -1);
    z[(bal >= 0)].pb(i);
  }
  int e = (z[1].size() > 1);
  f(2 * n, s[z[e][0]], s[z[e][1]], char(e + '0'));
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