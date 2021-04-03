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

int n;
string a, b;

bool val() {
  vector<int> cnt[2];
  cnt[0].resize(n, 0);
  cnt[1].resize(n, 0);
  cnt[0][0] = a[0] == '0';
  cnt[1][0] = a[0] == '1';
  for (int i = 1; i < n; i++) {
    cnt[0][i] = cnt[0][i - 1] + (a[i] == '0');
    cnt[1][i] = cnt[1][i - 1] + (a[i] == '1');
  }
  bool inv = false;
  for (int i = n - 1; i >= 0; i--) {
    if ((a[i] == b[i] && !inv) || (a[i] != b[i] && inv)) continue;
    if (cnt[0][i] != cnt[1][i]) return false;
    inv = !inv;
  }
  return true;
}

void solve() {
  cin >> n >> a >> b;

  if (val())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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