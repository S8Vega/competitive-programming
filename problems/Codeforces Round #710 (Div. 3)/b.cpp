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

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ans = 0, i, j;
  for (i = 0; i < n; i++) {
    if (s[i] == '*') {
      ans++;
      s[i] = 'X';
      break;
    }
  }
  while (i < n) {
    for (j = min(i + k, n - 1); j >= 0; j--) {
      if (s[j] == 'X') {
        i = n;
        break;
      }
      if (s[j] == '*') {
        ans++;
        s[j] = 'X';
        i = j;
        break;
      }
    }
  }
  for (i = n - 1; i >= 0; i--) {
    if (s[i] == 'X') break;
    if (s[i] == '*') {
      s[i] = 'X';
      ans++;
      break;
    }
  }
  cout << ans << endl;
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
g++ -pthread -Wall -Wshadow -std=c++17 -o main b.cpp -DLOCAL && ./main
*/