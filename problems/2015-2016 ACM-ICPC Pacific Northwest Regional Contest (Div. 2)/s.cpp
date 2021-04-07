#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXT = 1e6 + 5;
const int MAX = 3e5 + 5;

unordered_map<int, pair<int, int>> mp;
ll memo[MAXT];
ll dp(int t) {
  if (t > 1e6) return 0;
  ll &ans = memo[t];
  if (ans != -1) return ans;
  if (mp.count(t))
    ans = max(dp(t + 1), dp(t + mp[t].S) + mp[t].F);
  else
    ans = max(ans, dp(t + 1));
  return ans;
}
int main() {
#ifdef LOCAL
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#else
  fastIO;
#endif
  memset(memo, -1, sizeof memo);
  int n;
  cin >> n;
  // vector<int,pii> v(n);
  forn(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    mp[a] = {b, c};
  }
  cout << dp(0) << endl;

  return 0;
}