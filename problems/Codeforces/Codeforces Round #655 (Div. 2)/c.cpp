#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 2e5 + 10;
int n, a[N];

int main() {
#ifdef LOCAL
  freopen("c.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int t, l, r, cnt;
  cin >> t;
  while (t--) {
    cin >> n;
    cnt = 0, l = r = -1;
    forn(i, 0, n) {
      cin >> a[i];
      a[i]--;
      if (a[i] != i) {
        cnt++;
        if (l == -1) l = i;
        r = i;
      }
    }
    if (l == -1)
      cout << 0 << endl;
    else if (cnt == r - l + 1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main c.cpp -DLOCAL && ./main
*/