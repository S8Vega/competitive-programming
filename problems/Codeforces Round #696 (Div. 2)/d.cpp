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

const int N = 2e5 + 100;
int a[N], pref[N], suff[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  pref[0] = 0;
  for (int i = 1; i <= n; i++)
    if (pref[i - 1] < 0)
      pref[i] = -1;
    else
      pref[i] = a[i] - pref[i - 1];
  suff[n + 1] = 0;
  for (int i = n; i >= 1; i--)
    if (suff[i + 1] < 0)
      suff[i] = -1;
    else
      suff[i] = a[i] - suff[i + 1];
  bool yes = pref[n] == 0;
  for (int i = 1; i <= n - 1; i++)
    if (pref[i - 1] >= 0 && suff[i + 2] >= 0 && a[i + 1] - pref[i - 1] >= 0 &&
        a[i] - a[i + 1] + pref[i - 1] >= 0 &&
        suff[i + 2] - a[i] + a[i + 1] - pref[i - 1] == 0)
      yes = true;
  cout << (yes ? "YES" : "NO") << endl;
}

int main() {
#ifdef LOCAL
  freopen("d.txt", "r", stdin);
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
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/