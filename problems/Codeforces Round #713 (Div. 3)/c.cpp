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

int a, b;
string s;

void solve() {
  cin >> a >> b >> s;
  for (int l = 0, r = SZ(s) - 1; l < r; l++, r--) {
    if (s[l] != '?' && s[r] != '?' && s[l] != s[r]) {
      a = -1;
    }
    if (s[l] == '0') a--;
    if (s[l] == '1') b--;
    if (s[r] == '0') a--;
    if (s[r] == '1') b--;
    if ((s[l] != '?' && s[r] == '?') || (s[l] == '?' && s[r] != '?')) {
      if (s[l] == '1') {
        s[r] = '1';
        b--;
      } else if (s[l] == '0') {
        s[r] = '0';
        a--;
      } else if (s[r] == '0') {
        s[l] = '0';
        a--;
      } else {
        s[l] = '1';
        b--;
      }
    }
  }
  for (int l = 0, r = SZ(s) - 1; l < r; l++, r--) {
    if (s[r] == '?' && s[l] == '?') {
      if (a > 1) {
        s[l] = '0';
        s[r] = '0';
        a -= 2;
      } else {
        s[l] = '1';
        s[r] = '1';
        b -= 2;
      }
    }
  }
  // dbg(a, b, s);
  if (SZ(s) & 1) {
    if (s[SZ(s) / 2] == '?') {
      if (a > 0) {
        s[SZ(s) / 2] = '0';
        a--;
      } else {
        s[SZ(s) / 2] = '1';
        b--;
      }
    } else if (s[SZ(s) / 2] == '0')
      a--;
    else
      b--;
  }
  // dbg(a, b, s);
  if (a != 0 || b != 0)
    cout << -1 << endl;
  else
    cout << s << endl;
}

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
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