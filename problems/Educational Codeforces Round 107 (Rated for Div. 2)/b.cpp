#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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

int a, b, c;
string x, y;

void solve() {
  cin >> a >> b >> c;
  x = y = "1";
  for (int i = 1; i < a; i++) x += "0";
  for (int i = 1; i < b; i++) y += "0";
  if (a < b) {
    x[a - c] = '1';
  } else {
    y[b - c] = '1';
  }
  cout << x << ' ' << y << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}