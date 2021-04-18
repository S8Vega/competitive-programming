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

const int N = 2e5 + 10;
ll n, a[N];

void solve() {
  cin >> n;
  n += 2;
  ll sum = 0;
  map<ll, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    sum += a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    if (cnt[sum - a[i] - a[n - 1]] > 0 &&
        (a[i] == sum - a[n - 1] - a[i] || a[n - 1] == sum - a[n - 1] - a[i])) {
      for (int j = 0; j < n - 1; j++) {
        if (i == j) continue;
        cout << a[j] << ' ';
      }
      cout << endl;
      return;
    }
  }
  cout << -1 << endl;
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