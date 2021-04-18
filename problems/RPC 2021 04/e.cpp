#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... E>
void debug(T t, E... e) {
  cout << t << (sizeof...(e) ? " " : "");
  debug(e...);
}
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 10;
int n, c[N], bit[N + 1];
map<int, int> pos;

void add(int k, int val) {
  for (; k <= N; k += k & -k) bit[k] += val;
}

int rsq(int k) {
  int sum = 0;
  for (; k >= 1; k -= k & -k) sum += bit[k];
  return sum;
}

int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, 0, n) {
    cin >> c[i];
    pos[c[i]] = i + 1;
    add(i + 1, 1);
  }
  ll ans = 0;
  for (auto &x : pos) {
    // debug(rsq(1, x.S) - 1, rsq(x.S, n) - 1, x.F, x.S);
    ans += min(rsq(1, x.S), rsq(x.S, n)) - 1;
    add(x.S, -1);
  }
  cout << ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main e.cpp && ./main < e.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/