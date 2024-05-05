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

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;
int n, a[N];
map<int, int> cnt;

ll npr(ll n, ll k) {
  ll p = 1;
  for (int i = 0; i < k; i++) p = (p * (n - i)) % MOD;
  return p;
}

void solve() {
  cin >> n;
  cnt.clear();
  int x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (i) {
      x &= a[i];
    } else
      x = a[i];
  }
  if (cnt[x] > 1) {
    cout << (npr(cnt[x], 2) * npr(n - 2, n - 2)) % MOD << endl;
  } else
    cout << 0 << endl;
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