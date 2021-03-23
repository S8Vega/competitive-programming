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

const int N = 1e5 + 10;
ll n, c[N];

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
  int t;
  ll ans, sum, mn[2], cnt[2];
  cin >> t;
  while (t--) {
    cin >> n;
    cnt[0] = cnt[1] = n;
    ans = mn[0] = mn[1] = 1e15;
    sum = 0;
    forn(i, 0, n) {
      cin >> c[i];
      mn[i & 1] = min(mn[i & 1], c[i]);
      sum += c[i];
      cnt[i & 1]--;
      if (i) ans = min(ans, sum + mn[0] * cnt[0] + mn[1] * cnt[1]);
    }
    cout << ans << endl;
  }
  return 0;
}