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

int n, s;
vector<int> yes, no;
map<int, int> tiempo;

bool f() {
  for (int cur = yes.back(), i = SZ(yes) - 1; i >= 0; i--) {
    cur = min(cur, yes[i]);
    tiempo[cur--]++;
    if (cur < 0) return false;
  }
  for (int cur = 1, i = 0; i < SZ(no); i++) {
    if (tiempo[cur] == s) cur++;
    if (cur > no[i]) return false;
    tiempo[cur]++;
    // if (tiempo[cur] == s) cur++;
  }
  return true;
}

void solve() {
  cin >> s >> n;
  int x;
  char y;
  forn(i, 0, n) {
    cin >> x >> y;
    if (y == 'y')
      yes.pb(x);
    else
      no.pb(x);
  }
  sort(yes.begin(), yes.end());
  sort(no.begin(), no.end());
  if (f())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
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