#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... E>
void debug(T t, E... e) {
  cout << t << (sizeof...(e) ? " " : "");
  debug(e...);
}
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define SZ(v) ((int)(v.size()))
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
map<char, int> ch;
map<int, char> num;

bool check(string &s) {
  if (n == 0 && m == 0) return false;
  int x = 0, y = 0;
  for (char &c : s) {
    if (c == 'R') x++;
    if (c == 'L') x--;
    if (c == 'U') y++;
    if (c == 'D') y--;
    if (x == n && y == m) return false;
  }
  return true;
}

void solve() {
  string s;
  cin >> n >> m >> s;
  vector<int> cnt(4, 0);
  vector<int> perm = {0, 1, 2, 3};
  for (char &c : s) {
    cnt[ch[c]]++;
  }
  bool cnd = false;
  string cur;
  do {
    cur = "";
    for (int &id : perm) {
      forn(i, 0, cnt[id]) { cur += num[id]; }
    }
    if (check(cur)) {
      cout << cur << endl;
      cnd = true;
      break;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  if (!cnd) cout << "Impossible" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ch['R'] = 0;
  ch['L'] = 1;
  ch['U'] = 2;
  ch['D'] = 3;
  num[0] = 'R';
  num[1] = 'L';
  num[2] = 'U';
  num[3] = 'D';
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main e.cpp && ./main < e.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/