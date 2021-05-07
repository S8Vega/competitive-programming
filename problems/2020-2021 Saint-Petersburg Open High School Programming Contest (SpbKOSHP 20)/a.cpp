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
#define SZ(v) ((int)(v.size()))
typedef long long ll;
typedef pair<int, int> pii;

const int N = 110, MAX = 1e6 + 10;
int n, a[N];
bitset<MAX> bs;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  bs.reset();
  bs[0] = 1;
  ll sum = 0;
  forn(i, 0, n) {
    cin >> a[i];
    bs = bs | (bs << a[i]);
    bs[a[i]] = 1;
    sum += a[i];
    // debug(a[i], bs);
  }
  ll ans = 0, cur = 0;
  for (int i = sum; i >= 0; i--) {
    if (bs[i]) {
      ans += sum + 1 - cur++;
    }
  }
  cout << ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main a.cpp && for x in a*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/