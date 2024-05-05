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

const int N = 510;
ll n, l, r, s, a[N];
bitset<N> vis;

int sum(int x) { return x * (x + 1) / 2; }

void solve() {
  cin >> n >> l >> r >> s;
  l--, r--;
  vis.reset();
  memset(a, 0, sizeof a);
  int cur = n;
  for (int i = l; i <= r; i++) {
    while (cur + sum(r - i) > s && cur > 0) cur--;
    if (!cur) {
      cout << -1 << endl;
      return;
    }
    vis[cur] = 1;
    a[i] = cur;
    s -= cur--;
  }
  for (int i = 0, j = 1; i < n; i++) {
    if (!a[i]) {
      while (vis[j]) j++;
      a[i] = j;
      vis[j] = 1;
    }
  }
  if (s == 0) {
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
  } else
    cout << -1 << endl;
}

int main() {
#ifdef LOCAL
  freopen("e.txt", "r", stdin);
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