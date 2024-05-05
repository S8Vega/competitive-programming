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

inline int add(int a, int b, const int &mod) {
  return a + b >= mod ? a + b - mod : a + b;
}
inline int sbt(int a, int b, const int &mod) {
  return a - b < 0 ? a - b + mod : a - b;
}
inline int mul(int a, int b, const int &mod) { return 1ll * a * b % mod; }

const int X[] = {257, 359};
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 9};
vector<int> xpow[2];

struct hashing {
  vector<int> h[2];

  hashing(string &s) {
    int n = s.size();
    for (int j = 0; j < 2; ++j) {
      h[j].resize(n + 1);
      for (int i = 1; i <= n; ++i) {
        h[j][i] = add(mul(h[j][i - 1], X[j], MOD[j]), s[i - 1], MOD[j]);
      }
    }
  }
  // Hash del substring en el rango [i, j)
  ll value(int l, int r) {
    int a = sbt(h[0][r], mul(h[0][l], xpow[0][r - l], MOD[0]), MOD[0]);
    int b = sbt(h[1][r], mul(h[1][l], xpow[1][r - l], MOD[1]), MOD[1]);
    return (ll(a) << 32) + b;
  }
};

void calc_xpow(int mxlen) {
  for (int j = 0; j < 2; ++j) {
    xpow[j].resize(mxlen + 1, 1);
    for (int i = 1; i <= mxlen; ++i) {
      xpow[j][i] = mul(xpow[j][i - 1], X[j], MOD[j]);
    }
  }
}

void solve() {
  string a, b;
  cin >> a >> b;
  hashing ha(a), hb(b);
  int ans = 1e9;
  for (int i = 0; i < SZ(a); i++) {
    for (int j = i + 1; j <= SZ(a); j++) {
      for (int k = 0; k + j - i <= SZ(b); k++) {
        if (ha.value(i, j) == hb.value(k, k + j - i)) {
          ans = min(ans, SZ(a) + SZ(b) - 2 * (j - i));
        }
      }
    }
  }
  cout << min(ans, SZ(a) + SZ(b)) << endl;
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
  calc_xpow(30);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main c.cpp -DLOCAL && ./main
*/