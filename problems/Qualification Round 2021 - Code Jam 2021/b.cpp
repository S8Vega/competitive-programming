#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
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

const int N = 1e3 + 10, INF = 1e8;
int x, y, n, dp[N][2][2];
string s;
map<char, map<char, int>> mp;

int f(int i = 0, int a = 1, int b = 1) {
  if (i == n) return 0;
  int &ans = dp[i][a][b];
  if (ans < INF) return ans;
  if (a & b) {
    if (s[i] == '?')
      ans = min(f(i + 1, 0, 1), f(i + 1, 1, 0));
    else
      ans = f(i + 1, s[i] == 'C', s[i] == 'J');
    return ans;
  }
  char ant = (a == 1 ? 'C' : 'J');
  if (s[i] != '?') {
    ans = mp[ant][s[i]];
    ans += f(i + 1, s[i] == 'C', s[i] == 'J');
    return ans;
  }
  ans = mp[ant]['C'] + f(i + 1, 1, 0);
  ans = min(ans, mp[ant]['J'] + f(i + 1, 0, 1));
  return ans;
}

void solve() {
  cin >> x >> y >> s;
  mp['C']['J'] = x;
  mp['J']['C'] = y;
  forn(i, 0, n + 10) {
    forn(i1, 0, 2) {
      forn(i2, 0, 2) { dp[i][i1][i2] = INF; }
    }
  }
  n = SZ(s);
  cout << f() << endl;
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
  mp['C']['C'] = 0;
  mp['J']['J'] = 0;
  cin >> t;
  forn(i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main b.cpp -DLOCAL && ./main
*/