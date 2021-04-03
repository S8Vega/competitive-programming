#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

int n;
string s;

void create(int &ones, bool c) {
  string a = "";
  for (int i = 0, cnt = 0; i < n; i++) {
    if (s[i] == '0') {
      a += (c ? '(' : ')');
      c = !c;
    } else {
      a += (cnt < ones / 2 ? '(' : ')');
      cnt++;
    }
  }
  cout << a << endl;
}

void solve() {
  cin >> n >> s;
  int ones = 0;
  for (int i = 0; i < n; i++) {
    ones += s[i] == '1';
  }
  if (ones % 2 || s[0] == '0' || s[n - 1] == '0') {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  create(ones, true);
  create(ones, false);
}

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/