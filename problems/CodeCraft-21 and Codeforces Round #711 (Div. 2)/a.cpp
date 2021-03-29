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

ll sum_digits(ll x) {
  ll sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

ll f(ll x) { return __gcd(x, sum_digits(x)); }

void test() {
  for (ll i = 1e15 + 123456789; i < 1e15 + 123456789 + 50; i++) {
    if (f(i) > 1) dbg(i, sum_digits(i), f(i));
  }
}

void solve() {
  ll x;
  cin >> x;
  while (f(x) == 1) x++;
  cout << x << endl;
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