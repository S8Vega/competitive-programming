#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
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

const int M = 1e9 + 7;

int expmod(int b, int e, int m) {
  int ans = 1;
  while (e) {
    if (e & 1) ans = (1ll * ans * b) % m;
    b = (1ll * b * b) % m;
    e /= 2;
  }
  return ans;
}

int invmod(int a, int m) { return expmod(a, m - 2, m); }

ll mulmod(ll a, ll b, ll m) {
  ll r = a * b - (ll)((long double)a * b / m + .5) * m;
  return r < 0 ? r + m : r;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum[n + 1];
  sum[n] = 0;
  ll ans = 0;
  int pp = 0;
  for (auto &x : a) cin >> x;
  for (int i = n - 1; i >= 0; i--) {
    sum[i] = a[i] + sum[i + 1];
    sum[i] = sum[i] % M;
  }
  // forn(i, 0, n) dbg(i, a[i], sum[i]);
  forn(i, 0, n) {
    ans += mulmod(a[i], sum[i + 1], M);
    pp += n - i - 1;
    pp = pp % M;
  }
  // dbg(ans);
  cout << mulmod(ans, invmod(pp, M), M) << endl;
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

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

Linux command
g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done

Powershell command
cd $dir && g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -o
main $fileName && $testcase = '>>> name'; foreach ($file in Get-ChildItem
$fileNameWithoutExt*.txt) { echo  $testcase.Replace('name', $file.Name);
Get-Content $file.Name | ./main; echo
==========================================; }
*/