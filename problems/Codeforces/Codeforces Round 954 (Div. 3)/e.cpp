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

const int N = 1e5 + 5;
int n, k, a[N];

ll f(vector<int> &v) {
  ll ans = 1e9;
  int vn = SZ(v);
  ll s_odd[vn + 1], s_even[vn + 1];
  s_odd[0] = s_even[0] = 0;
  forn(i, 0, vn) {
    s_odd[i + 1] = s_odd[i] + (i & 1 ? v[i] : 0);
    s_even[i + 1] = s_even[i] + (i & 1 ? 0 : v[i]);
  }
  // cout << endl;
  // forn(i, 0, vn + 1) { cout << s_even[i] << " "; }
  // cout << endl;
  // forn(i, 0, vn + 1) { cout << s_odd[i] << " "; }
  // cout << endl;
  forn(i, 0, vn) {
    ll cur = 0;
    if (i & 1) {
      cur = s_odd[i] - s_even[i];
      cur += (s_even[vn] - s_even[i + 1]) - (s_odd[vn] - s_odd[i + 1]);
    } else {
      cur = s_odd[i] - s_even[i];
      cur += (s_even[vn] - s_even[i + 1]) - (s_odd[vn] - s_odd[i]);
    }
    // dbg(i, cur);
    ans = min(ans, cur);
  }
  return ans;
}

void solve() {
  cin >> n >> k;
  map<int, vector<int>> remainder;
  forn(i, 0, n) {
    cin >> a[i];
    remainder[a[i] % k].pb(a[i] / k);
  }
  int cant_remainder_odd = 0;
  for (auto x : remainder) {
    cant_remainder_odd += SZ(x.S) & 1;
  }
  if (cant_remainder_odd > 1) {
    cout << -1 << endl;
    return;
  }
  ll ans = 0;
  for (auto x : remainder) {
    vector<int> &v = x.S;
    sort(v.begin(), v.end());
    if (SZ(v) & 1) {
      ans += f(v);
    } else {
      ll cur = 0;
      forn(i, 0, SZ(v)) cur += (i & 1 ? v[i] : -v[i]);
      ans += cur;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v = {2, 3, 5, 8, 9, 10, 15, 16, 17};
  // dbg(f(v));
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