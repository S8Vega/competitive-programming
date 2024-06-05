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
  ll n, m;
  cin >> n >> m;
  ll l = max(0LL, n - m), r = n + m, ans = 0;
  for (int i = 31; ~i; --i) {
    if ((l & (1LL << i)) || (r & (1LL << i)) ||
        (l >> (i + 1)) != (r >> (i + 1))) {
      ans |= (1LL << i);
    }
  }
  cout << ans << endl;
}

void init() {
  int n = 35;
  int a[n];
  forn(i, 0, n) { a[i] = i; }
  forn(i, 0, n) {
    cout << ">>> " << (i < 10 ? "0" : "") << i << ": ";
    forn(j, 0, n) { cout << (a[j] < 10 ? "0" : "") << a[j] << " "; }
    cout << endl;
    int b[n];
    b[0] = a[0] | a[1];
    forn(j, 1, n - 1) { b[j] = a[j - 1] | a[j] | a[j + 1]; }
    b[n - 1] = a[n - 1] | a[n - 2];
    forn(j, 0, n) { a[j] = b[j]; }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // init();
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