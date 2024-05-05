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

const int N = 1e5 + 10;
int n;
ll sum[3], a[N], b[N];

int main() {
#ifdef LOCAL
  freopen("j.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  cin >> n;
  forn(i, 0, n) cin >> a[i];
  forn(i, 0, n) cin >> b[i];
  forn(i, 3, n) b[i % 3] += b[i];
  forn(i, 0, n) forn(j, 0, 3) sum[(i + j) % 3] += a[i] * b[j];
  cout << sum[1] << ' ' << sum[2] << ' ' << sum[0] << endl;
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main j.cpp -DLOCAL && ./main
*/