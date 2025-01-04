#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

ull f(ull a, ull b, ull c) { return (a ^ b) + (b ^ c) + (a ^ c); }

ull inv(ull x, ull n) {
  ull mask = (1 << n) - 1;
  return x ^ mask;
}

int count_bits(ull x) {
  int cnt = 0;
  while (x > 0) {
    x >>= 1;
    cnt++;
  }
  return cnt;
}

void test(ull l, ull r) { forn(i, l + 1, r) dbg(l, i, r, f(l, i, r)); }

void solve() {
  ull l, r, m;
  cin >> l >> r;
  // test(l, r);
  ull ans = l;
  // dbg(r, bitset<10>(r));
  for (int i = count_bits(r); i > 0; i--) {
    m = inv(r, i);
    // dbg(m, bitset<10>(m));
    // dbg(i, m, f(l, m, r));
    if (m > l && m < r && (ans == l || f(l, m, r) > f(l, ans, r))) ans = m;
  }
  cout << l << " " << ans << " " << r << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  // t = 1;
  while (t--) {
    solve();
  }
  return 0;
}