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
  string s;
  cin >> s;
  int ind1 = 0, ind2 = -1;
  forn(i, 1, SZ(s)) {
    if (s[i] != s[ind1]) {
      ind2 = i;
      break;
    }
  }
  if (ind2 == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << s[ind2];
    forn(i, 0, SZ(s)) {
      if (i != ind2) {
        cout << s[i];
      }
    }
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