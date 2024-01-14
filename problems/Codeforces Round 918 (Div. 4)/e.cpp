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
  ll a[n], sum[n];
  forn(i, 0, n) {
    cin >> a[i];
    if (i & 1) a[i] *= -1;
    sum[i] = a[i] + (i ? sum[i - 1] : 0);
  }

  // forn(i, 0, n) { cout << a[i] << " "; }
  // cout << endl;
  // forn(i, 0, n) { cout << sum[i] << " "; }
  // cout << endl;

  set<ll> st;
  for (int i = n - 1; i >= 0; i--) {
    if (st.count(sum[i]) || sum[i] == 0) {
      cout << "YES" << endl;
      return;
    }
    st.insert(sum[i]);
  }
  cout << "NO" << endl;
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

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/