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

void solve() {
  cin >> n >> a >> b;
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      ans.pb(i);
    }
  }
  char cur = a[n - 1];
  for (int i = n - 1; i >= 0; i--) {
    if (b[i] != cur) {
      ans.pb(i + 1);
      cur = cur == '0' ? '1' : '0';
    }
  }
  cout << SZ(ans) << endl;
  for (int &x : ans) cout << x << ' ';
  cout << endl;
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