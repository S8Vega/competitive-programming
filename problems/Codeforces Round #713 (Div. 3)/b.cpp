#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 410;
int n;
string s[N];

void solve() {
  cin >> n;
  pii p[2];
  p[0] = {-1, -1};
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '*') {
        if (p[0].F == -1) {
          p[0].F = i, p[0].S = j;
        } else {
          p[1].F = i, p[1].S = j;
        }
      }
    }
  }
  if (p[0].F > p[1].F) swap(p[0], p[1]);
  if (p[0].F == p[1].F) {
    if (p[0].F == n - 1) {
      s[p[0].F - 1][p[0].S] = '*';
      s[p[1].F - 1][p[1].S] = '*';
    } else {
      s[p[0].F + 1][p[0].S] = '*';
      s[p[1].F + 1][p[1].S] = '*';
    }
  } else if (p[0].S == p[1].S) {
    if (p[0].S == n - 1) {
      s[p[0].F][p[0].S - 1] = '*';
      s[p[1].F][p[1].S - 1] = '*';
    } else {
      s[p[0].F][p[0].S + 1] = '*';
      s[p[1].F][p[1].S + 1] = '*';
    }
  } else {
    s[p[0].F][p[1].S] = '*';
    s[p[1].F][p[0].S] = '*';
  }
  for (int i = 0; i < n; i++) cout << s[i] << endl;
}

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/