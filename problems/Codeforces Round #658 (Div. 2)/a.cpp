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
  int n1, n2;
  cin >> n1 >> n2;
  map<int, int> rep;
  vector<int> v(n2);
  for (int i = 0, u; i < n1; i++) {
    cin >> u;
    rep[u]++;
  }
  for (int i = 0; i < n2; i++) cin >> v[i];
  for (int i = 0; i < n2; i++) {
    if (rep[v[i]]) {
      cout << "YES" << endl;
      cout << 1 << ' ' << v[i] << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
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
g++ -pthread -Wall -Wshadow -std=c++17 -o main a.cpp -DLOCAL && ./main
*/