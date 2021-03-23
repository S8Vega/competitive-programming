#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
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

bool f() {
  int uno = 0;
  forn(i, 0, n) {
    uno += s[i] == '1';
    if (i + 1 < n) {
      if (uno && s[i] == '0' && s[i + 1] == '0') {
        if (uno == 1)
          uno--;
        else
          return false;
      } else if (uno && s[i] == '0')
        uno--;
    }
  }
  return true;
}

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
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
    cin >> s;
    n = SZ(s);
    if (f())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/