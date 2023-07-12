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

string m[3];

void f() {
  for (int i = 0; i < 3; i++) {
    dbg(m[i]);
    if (m[i][0] != '.' && m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
      cout << m[i][0] << endl;
      return;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (m[0][i] != '.' && m[0][i] == m[1][i] && m[1][i] == m[2][i]) {
      cout << m[0][i] << endl;
      return;
    }
  }
  if (m[1][1] != '.' && ((m[0][0] == m[1][1] && m[1][1] == m[2][2]) ||
                         (m[0][2] == m[1][1] && m[1][1] == m[2][0])))
    cout << m[1][1] << endl;
  else
    cout << "DRAW" << endl;
}

void solve() {
  for (string &s : m) {
    cin >> s;
  }
  f();
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