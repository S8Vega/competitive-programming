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

void solve() {
  int n, k;
  cin >> n >> k;
  if (!k) {
    cout << -1 << endl;
    return;
  }
  for (int i = 1; i < k; i++) {
    cout << i + 1 << ' ';
  }
  cout << 1;
  for (int i = k + 1; i <= n; i++) cout << ' ' << i;
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}