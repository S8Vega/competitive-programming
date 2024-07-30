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

const int NM = 105;
int n, m, a[NM][NM];

int get(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) return 0;
  return a[i][j];
}

int get_max(int i, int j) {
  int ans = max(get(i - 1, j), get(i + 1, j));
  ans = max(ans, get(i, j - 1));
  ans = max(ans, get(i, j + 1));
  return ans;
}

void solve() {
  cin >> n >> m;
  forn(i, 0, n) {
    forn(j, 0, m) { cin >> a[i][j]; }
  }
  forn(i, 0, n) {
    forn(j, 0, m) {
      int mx = get_max(i, j);
      if (a[i][j] > mx) a[i][j] = mx;
    }
  }
  forn(i, 0, n) {
    forn(j, 0, m) { cout << a[i][j] << " "; }
    cout << endl;
  }
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