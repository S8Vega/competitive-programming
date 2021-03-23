#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t, n, k, x, y, z;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n % k == 0) {
      forn(i, 0, k) cout << n / k << " ";
      cout << endl;
      continue;
    }
    forn(i, 0, k - 3) cout << 1 << " ";
    n = n - (k - 3);
    if (n % 2 == 1) {
      x = 1;
      y = n / 2;
      z = n / 2;
    } else {
      if ((n / 2) % 2 == 1) {
        x = 2;
        y = (n - 2) / 2;
        z = (n - 2) / 2;
      } else {
        x = n / 2;
        y = n / 4;
        z = n / 4;
      }
    }
    cout << x << " " << y << " " << z << endl;
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main c.cpp -DLOCAL && ./main
*/