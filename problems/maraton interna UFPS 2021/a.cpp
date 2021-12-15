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

const int MX = 1e6 + 1000;
bool marked[MX + 1];
vector<int> primes;
vector<int> gemelos;
int ans[MX + 1];
/// O(MX log(log(MX)))
void sieve() {
  marked[0] = marked[1] = true;
  for (int i = 2; i <= MX; i++) {
    if (marked[i]) continue;
    primes.push_back(i);
    for (ll j = 1ll * i * i; j <= MX; j += i) marked[j] = true;
  }

  gemelos.pb(3);
  forn(i, 1, SZ(primes)) {
    if (primes[i] - primes[i - 1] == 2) {
      if (gemelos.back() != primes[i - 1]) gemelos.pb(primes[i - 1]);
      gemelos.pb(primes[i]);
    }
  }

  ans[0] = ans[1] = ans[2] = 3;
  int id = 0;
  // forn(i, 0, 30) dbg(i, gemelos[i]);
  forn(i, 3, 1e6 + 1) {
    if (id >= MX - 1) break;
    if (abs(gemelos[id] - i) < abs(gemelos[id + 1] - i)) {
      ans[i] = gemelos[id];
    } else {
      ans[i] = gemelos[++id];
    }
  }
}

void solve() {
  int x;
  cin >> x;
  cout << ans[x] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve();
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