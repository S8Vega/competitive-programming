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

int n;
string s;

int num(string ss) {
  // dbg(ss);
  int res = 0;
  for (char c : ss) {
    res = res * 10 + c - '0';
  }
  // dbg(res);
  return res;
}

const int N = 21, M = 2000;
int dp[N][M][2];

int f(int i, int cur, int flag) {
  if (i > n || cur >= M || (i == n && !flag)) return 1e9;
  if (i == n) return cur;
  int &ans = dp[i][cur][flag];
  if (ans != -1) return ans;
  ans = 1e9;
  if (flag) {
    ans = min(ans, f(i + 1, cur + num(string(1, s[i])), 1));
    ans = min(ans, f(i + 1, (i == 0 ? 1 : cur) * num(string(1, s[i])), 1));
  } else {
    if (i + 1 < n) {
      ans = min(ans, f(i + 2, cur + num(string(1, s[i]) + s[i + 1]), 1));
      ans = min(
          ans,
          f(i + 2, (i == 0 ? 1 : cur) * num(string(1, s[i]) + s[i + 1]), 1));
    }
    ans = min(ans, f(i + 1, cur + num(string(1, s[i])), 0));
    ans = min(ans, f(i + 1, (i == 0 ? 1 : cur) * num(string(1, s[i])), 0));
  }
  return ans;
}

void reset() {
  forn(i, 0, N) {
    forn(j, 0, M) {
      forn(k, 0, 2) { dp[i][j][k] = -1; }
    }
  }
}

void solve() {
  cin >> n >> s;
  int ans = 0;
  // dbg(n, s);
  if (n == 2)
    cout << num(string(1, s[0]) + s[1]) << endl;
  else if (n == 3) {
    ans = num(string(1, s[0])) + num(string(1, s[1]) + s[2]);
    ans = min(ans, num(string(1, s[0]) + s[1]) + num(string(1, s[2])));
    ans = min(ans, num(string(1, s[0])) * num(string(1, s[1]) + s[2]));
    ans = min(ans, num(string(1, s[0]) + s[1]) * num(string(1, s[2])));
    cout << ans << endl;
  } else if (s.find('0') != string::npos) {
    cout << 0 << endl;
  } else {
    reset();
    cout << f(0, 0, 0) << endl;
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