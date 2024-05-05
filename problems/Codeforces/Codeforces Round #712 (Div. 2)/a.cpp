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

bool is_palindrome(string s) {
  int n = SZ(s);
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return 0;
  }
  return 1;
}

void solve() {
  string s;
  cin >> s;
  if (!is_palindrome('a' + s)) {
    cout << "YES" << endl;
    cout << 'a' + s << endl;
  } else if (!is_palindrome(s + 'a')) {
    cout << "YES" << endl;
    cout << s + 'a' << endl;
  } else
    cout << "NO" << endl;
}

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
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
g++ -pthread -Wall -Wshadow -std=c++17 -o main a.cpp -DLOCAL && ./main
*/