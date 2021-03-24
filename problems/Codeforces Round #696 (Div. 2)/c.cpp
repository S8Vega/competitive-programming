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

const int N = 2010;
int n, a[N];
vector<pii> ans;
multiset<int> ms;

bool f(int x) {
  ans.clear();
  ms.clear();
  forn(i, 0, n) ms.insert(a[i]);
  while (SZ(ms)) {
    int mx = *ms.rbegin();
    ms.erase(ms.find(mx));
    auto it = ms.find(x - mx);
    if (it == ms.end()) return false;
    ans.pb({*it, mx});
    x = mx;
    ms.erase(it);
  }
  return true;
}

void solve() {
  cin >> n;
  n *= 2;
  forn(i, 0, n) cin >> a[i];
  sort(a, a + n);
  forn(i, 0, n - 1) {
    int mx = a[n - 1] + a[i];
    if (f(mx)) {
      cout << "YES" << endl << mx << endl;
      for (pii x : ans) cout << x.F << ' ' << x.S << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main c.cpp -DLOCAL && ./main
*/