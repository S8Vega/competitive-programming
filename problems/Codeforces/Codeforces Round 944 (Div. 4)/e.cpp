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

void solve() {
  ll n, k, q;
  cin >> n >> k >> q;
  vector<ll> d(k + 1), t(k + 1);
  d[0] = t[0] = 0;
  forn(i, 1, k + 1) cin >> d[i];
  forn(i, 1, k + 1) cin >> t[i];
  ll qq;
  while (q--) {
    cin >> qq;
    int l = distance(d.begin(), lower_bound(d.begin(), d.end(), qq));
    if (d[l] > qq) l--;
    // dbg(qq, l, d[l], t[l]);
    if (d[l] == qq) {
      cout << t[l] << ' ';
      continue;
    }
    ll tt = t[l + 1] - t[l];
    ll dd = d[l + 1] - d[l];
    ll ans = t[l] + (qq - d[l]) * tt / dd;
    // dbg(qq, tt, dd, vv, ans);
    cout << ans << ' ';
  }
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