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

int n, sum[2], incognito[2];
string s;

void print(bool cond) {
  if (cond) {
    cout << "Bicarp" << endl;
  } else {
    cout << "Monocarp" << endl;
  }
}

bool f() {
  forn(i, 0, n) {
    if (s[i] == '?') {
      incognito[i < n / 2]++;
    } else {
      sum[i < n / 2] += s[i] - '0';
    }
  }
  if (incognito[0] == incognito[1]) {
    return sum[0] == sum[1];
  }
  if (incognito[0] > incognito[1]) {
    incognito[0] -= incognito[1];
    return (sum[0] + incognito[0] / 2 * 9 == sum[1]);
  }
  incognito[1] -= incognito[0];
  return (sum[1] + incognito[1] / 2 * 9 == sum[0]);
}

void solve() {
  cin >> n >> s;
  print(f());
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