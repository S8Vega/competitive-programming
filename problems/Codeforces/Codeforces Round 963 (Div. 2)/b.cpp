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
  int n;
  cin >> n;
  vector<ll> a(n);
  int odd = 0, i_odd = -1, i_even = -1;
  forn(i, 0, n) {
    cin >> a[i];
    odd += a[i] & 1;
  }
  if (odd == 0 || odd == n) {
    cout << 0 << endl;
    return;
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] & 1) {
      i_odd = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!(a[i] & 1)) {
      i_even = i;
      break;
    }
  }

  int ans = 0;
  forn(i, 0, n) {
    if (a[i] & 1) continue;
    if (a[i] > a[i_odd]) {
      a[i_odd] += a[i_even];
      a[i] += a[i_odd];
      i_odd = i;
      ans += 2;
    } else {
      a[i] += a[i_odd];
      i_odd = i;
      ans++;
    }
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