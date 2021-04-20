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

const int N = 1e7 + 10;
ll ans[N], sieve[N];

void init() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      sieve[j] += i;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    if (sieve[i] < N) ans[sieve[i]] = i;
  }
}

void solve() {
  int n;
  cin >> n;
  if (ans[n])
    cout << ans[n] << endl;
  else
    cout << -1 << endl;
}

int main() {
#ifdef LOCAL
  freopen("g.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  init();
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