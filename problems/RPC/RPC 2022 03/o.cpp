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

int findLastIndex(string& s, char x) {
  for (int i = SZ(s) - 1; i >= 0; --i) {
    if (s[i] == x) return i;
  }
}

int findFirstIndex(string& s, char x) {
  for (int i = 0; i < SZ(s); i++)
    if (s[i] == x) return i;
}

void solve() {
  string s;
  cin >> s;
  string ans = "";
  int firstIndex = findFirstIndex(s, 'U');
  int lastIndex = findLastIndex(s, 'F');

  forn(i, 0, SZ(s)) {
    if (i < firstIndex)
      ans += "-";
    else if (i == firstIndex)
      ans += "U";
    else if (i < lastIndex)
      ans += "C";
    else if (i == lastIndex)
      ans += "F";
    else
      ans += "-";
  }

  cout << ans << endl;
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