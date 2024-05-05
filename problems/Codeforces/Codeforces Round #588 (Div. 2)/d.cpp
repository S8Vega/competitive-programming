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

const int N = 7e3 + 10;
int n;
pair<ll, int> p[N];
bool used[N];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i].F;
  for (int i = 0; i < n; i++) cin >> p[i].S;
  sort(p, p + n);
  ll ans = 0;
  for (int i = 0, j; i < n; i = j + 1) {
    for (j = i; j < n && p[i].first == p[j].first; j++)
      ;
    j--;
    if (j > i) {
      for (int k = i; k <= j; k++) ans += p[k].second, used[k] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      for (int j = 0; j < n; j++)
        if (!used[j]) {
          if ((p[i].first & p[j].first) == p[j].first) {
            used[j] = 1, ans += p[j].second;
          }
        }
    }
  }
  cout << ans << endl;
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
  solve();
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp -DLOCAL && ./main
*/