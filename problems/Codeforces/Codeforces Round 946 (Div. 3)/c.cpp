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

const ll MX = 1e8;

ll fac(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

ll combi(ll n, ll r) { return fac(n) / (fac(r) * fac(n - r)); }

ll f(ll x, ll i) { return x * MX + i; }

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }
  int x, y, z;
  map<pair<pii, int>, ll> m;
  ll ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    x = a[i - 1];
    y = a[i];
    z = a[i + 1];
    m[{{x, y}, 0}]++;
    m[{{0, y}, z}]++;
    m[{{x, 0}, z}]++;
    m[{{x, y}, z}]++;

    ans += m[{{x, y}, 0}];
    ans += m[{{0, y}, z}];
    ans += m[{{x, 0}, z}];
    ans -= (m[{{x, y}, z}] * 3);
  }
  cout << ans << endl;
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