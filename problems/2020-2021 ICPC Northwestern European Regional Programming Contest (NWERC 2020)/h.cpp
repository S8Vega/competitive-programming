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

const int N = 1e5 + 5;
int n, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, 0, n) cin >> a[i];
  sort(a, a + n);
  vector<int> v;
  for (int l = 0, r = n - 1, c = 0; l <= r;) {
    if (c) {
      v.pb(a[r--]);
    } else {
      v.pb(a[l++]);
    }
    c = !c;
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << v[i] << " \n"[i == 0];
  }
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main h.cpp && for x in h*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/