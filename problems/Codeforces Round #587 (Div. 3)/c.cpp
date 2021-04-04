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
  int x[6] = {}, y[6] = {};
  for (int i = 0; i < 6; ++i) {
    cin >> x[i] >> y[i];
    x[i] *= 2;
    y[i] *= 2;
  }
  --x[2];
  ++x[3];
  --x[4];
  ++x[5];
  --y[2];
  ++y[3];
  --y[4];
  ++y[5];
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (x[0] <= x[i] && x[i] <= x[1] && y[0] <= y[j] && y[j] <= y[1] &&
          (x[i] <= x[2] || x[3] <= x[i] || y[j] <= y[2] || y[3] <= y[j]) &&
          (x[i] <= x[4] || x[5] <= x[i] || y[j] <= y[4] || y[5] <= y[j])) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
#ifdef LOCAL
  freopen("main.txt", "r", stdin);
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
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/