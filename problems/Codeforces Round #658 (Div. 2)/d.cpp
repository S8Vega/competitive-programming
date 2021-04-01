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

bool validate(vector<int> &v, vector<int> &a, vector<int> &b) {
  int id[2];
  if (SZ(a) != SZ(b)) {
    if (SZ(a) > SZ(b)) swap(a, b);
    id[1] = SZ(b) - 1;
    while (SZ(a) < SZ(b)) {
      a.pb(b[id[1]--]);
    }
  }
  id[0] = id[1] = 0;
  int n = SZ(v) / 2;
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
  for (int i = 0; i < n; i++) cout << b[i] << ' ';
  cout << endl;

  for (int i = 0; i < SZ(v); i++) {
    if (v[i] != min(a[id[0]], b[id[1]])) return false;
    if (a[id[0]] < b[id[1]])
      id[0]++;
    else
      id[1]++;
    if (id[0] == n || id[1] == n) return false;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  n *= 2;
  vector<int> p;
  for (int i = 0, u; i < n; i++) {
    cin >> u;
    p.pb(u);
  }
  bool cur = 0;
  int u, v;
  vector<int> a[2];
  a[0].pb(p[0]);
  u = p[0];
  for (int i = 1; i < n; i++) {
    v = p[i];
    if (u > v) {
      u = v;
      cur = !cur;
    }
    a[cur].pb(p[i]);
  }
  if (validate(p, a[0], a[1]))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
#ifdef LOCAL
  freopen("d.txt", "r", stdin);
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