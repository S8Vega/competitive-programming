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
  string s;
  cin >> s;
  int x = 0, y = 0, x2 = 0, y2 = 0, k = 0;
  string ans = "";
  map<char, int> mp;
  forn(i, 0, n) {
    if (s[i] == 'N' && mp[s[i]] == 0) {
      y++;
      ans += 'H';
    } else if (s[i] == 'S' && mp[s[i]] == 0) {
      y--;
      ans += 'H';
    } else if (s[i] == 'E' && mp[s[i]] == 1) {
      x++;
      ans += 'H';
    } else if (s[i] == 'W' && mp[s[i]] == 1) {
      x--;
      ans += 'H';
    }

    if (s[i] == 'N' && mp[s[i]] == 1) {
      y2++;
      ans += 'R';
    } else if (s[i] == 'S' && mp[s[i]] == 1) {
      y2--;
      ans += 'R';
    } else if (s[i] == 'E' && mp[s[i]] == 0) {
      x2++;
      ans += 'R';
    } else if (s[i] == 'W' && mp[s[i]] == 0) {
      x2--;
      ans += 'R';
    }
    if (mp[s[i]] == 1)
      mp[s[i]] = 0;
    else {
      mp[s[i]] = 1;
    }
  }
  if (x == x2 && y == y2) {
    map<char, int> h;

    forn(i, 0, n) { h[ans[i]]++; }
    // cout<<h['H']<<" "<<h['R']<<endl;
    if (h['H'] == 0 || h['R'] == 0)
      cout << "NO" << endl;
    else
      cout << ans << endl;
  } else {
    cout << "NO" << endl;
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