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
  int n, w, x, y;
  cin >> n >> w;
  multiset<int> ms;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ms.insert(x);
  }
  x = 1, y = w;
  while (SZ(ms)) {
    auto it = ms.upper_bound(y);
    if (it != ms.begin()) {
      it--;
      y -= *it;
      ms.erase(it);
    } else {
      y = w;
      x++;
    }
  }
  cout << x << endl;
}

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
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
g++ -pthread -Wall -Wshadow -std=c++17 -o main b.cpp -DLOCAL && ./main
*/