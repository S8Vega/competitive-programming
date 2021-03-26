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

const int N = 10;
int n, c, a[N], b[N];

int f() {
  int ans = 0;
  a[n] = 1e5;
  for (int i = 0; i < n - 1; i++) {
    int j = n;
    for (int jj = i; jj < n; jj++) {
      if (a[jj] < a[j]) j = jj;
    }
    ans += j - i + 1;
    reverse(a + i, a + j + 1);
  }
  return ans;
}

void solve() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) b[i] = i + 1;
  do {
    for (int i = 0; i < n; i++) a[i] = b[i];
    int k = f();
    if (k == c) {
      for (int i = 0; i < n; i++) cout << b[i] << " \n"[i + 1 == n];
      return;
    }
  } while (next_permutation(b, b + n));
  cout << "IMPOSSIBLE" << endl;
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
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/