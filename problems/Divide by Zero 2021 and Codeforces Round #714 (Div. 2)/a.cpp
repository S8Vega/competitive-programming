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

const int N = 1e2 + 10;
int n, k, a[N];

void solve() {
  cin >> n >> k;
  if ((n - 1) / 2 < k) {
    cout << -1 << endl;
    return;
  }
  int l = 1, r = n, pk = k, c = 0;
  for (int i = 0; i < n; i++) {
    if (!i || pk <= 0)
      a[i] = l++;
    else {
      if (c)
        a[i] = r--, pk--;
      else
        a[i] = l++;
    }
    c = !c;
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
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