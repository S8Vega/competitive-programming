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

const int N = 110;
int n, a[N];
map<int, pii> rep;

void solve() {
  cin >> n;
  rep.clear();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    rep[a[i]] = {i, rep[a[i]].S + 1};
  }
  for (auto &x : rep) {
    if (x.S.S == 1) {
      cout << x.S.F + 1 << endl;
      break;
    }
  }
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