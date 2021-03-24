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

const int MX = 1e6;
bool marked[MX + 1];
vector<int> primes;

void sieve() {
  marked[0] = marked[1] = true;
  for (int i = 2; i <= MX; i++) {
    if (marked[i]) continue;
    primes.push_back(i);
    for (ll j = 1ll * i * i; j <= MX; j += i) marked[j] = true;
  }
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
  sieve();
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int id1 = lower_bound(primes.begin(), primes.end(), n + 1) - primes.begin();
    int id2 = lower_bound(primes.begin(), primes.end(), primes[id1] + n) -
              primes.begin();

    // dbg(id1, id2, SZ(primes));
    // dbg(n, primes[id1], primes[id2]);
    cout << 1ll * primes[id1] * primes[id2] << endl;
  }
  return 0;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp -DLOCAL && ./main
*/