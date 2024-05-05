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

const int mod = 1e9, N = 1 << 8;

struct matrix {
  vector<vector<int>> v;
  int n, m;

  matrix(int n = N, int m = N, bool o = false)
      : n(n), m(m), v(n, vector<int>(m)) {
    if (o)
      while (n--) v[n][n] = 1;
  }

  matrix operator*(const matrix& o) {
    matrix ans(n, o.m);
    for (int i = 0; i < n; i++)
      for (int k = 0; k < m; k++)
        if (v[i][k])
          for (int j = 0; j < o.m; j++)
            ans[i][j] = (1ll * v[i][k] * o.v[k][j] + ans[i][j]) % mod;
    return ans;
  }

  vector<int>& operator[](int i) { return v[i]; }
};

matrix pow(matrix b, ll e) {
  matrix ans(b.n, b.m, true);
  while (e) {
    if (e & 1) ans = ans * b;
    b = b * b;
    e /= 2;
  }
  return ans;
}

matrix transitions;

void gen(int n, int cur_pos, int init_mask, int mask, int new_mask) {
  if (cur_pos == n) {
    if (mask == (1 << n) - 1) transitions.v[init_mask][new_mask]++;
    return;
  }
  if (mask & (1 << cur_pos)) {
    gen(n, cur_pos + 1, init_mask, mask, new_mask);
    return;
  }
  gen(n, cur_pos + 1, init_mask, mask | (1 << cur_pos), new_mask);
  gen(n, cur_pos + 1, init_mask, mask | (1 << cur_pos),
      new_mask | (1 << cur_pos));
  if (cur_pos + 1 < n && !(mask & (1 << (cur_pos + 1))))
    gen(n, cur_pos + 2, init_mask, mask | (1 << cur_pos) | (1 << (cur_pos + 1)),
        new_mask);
}

void solve() {
  ll n, m;
  cin >> n >> m;
  transitions = matrix();
  for (int i = 0; i < (1 << n); i++) gen(n, 0, i, i, 0);
  transitions = pow(transitions, m);
  cout << transitions.v[0][0] << endl;
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
  solve();
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main c.cpp -DLOCAL && ./main
*/