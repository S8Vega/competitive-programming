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
set<int> st;
map<int, int> rep;

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
  int t, x;
  cin >> t;
  while (t--) {
    cin >> n;
    st.clear();
    rep.clear();
    forn(i, 0, n) {
      cin >> x;
      st.insert(x);
      rep[x]++;
    }
    for (int y : st) cout << y << ' ';
    for (auto y : rep) {
      while (y.S-- > 1) cout << y.F << ' ';
    }
    cout << endl;
  }
  return 0;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/