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
typedef long double ld;

const int N = 1e5 + 5;
const ld INF = 1e18;
int n, x[N], v[N];

ld time(int i, int j) {
  if (v[i] == v[j]) return INF;
  ld ans = 1.0 * (x[j] - x[i]) / (v[i] - v[j]);
  if (ans < 0) return INF;
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, 0, n) cin >> x[i] >> v[i];
  set<int> ans;
  forn(i, 0, n) ans.insert(i);
  set<pair<ld, int>> times;
  ld t;
  forn(i, 0, n - 1) {
    t = time(i, i + 1);
    if (t < INF) times.insert({t, i});
  }
  int iu, iv, ju, jv;
  pair<double, int> pu;
  while (!times.empty()) {
    pu = *times.begin();
    times.erase(pu);
    iu = pu.S;
    auto it = ans.lower_bound(iu);
    iv = *ans.upper_bound(iu);
    // el de la izquierda
    if (it != ans.begin()) {
      it--;
      t = time(iu, *it);
      if (t < INF) times.erase({t, *it});
    }
    it = ans.upper_bound(iv);
    // el de la derecha
    if (it != ans.end()) {
      t = time(iv, *it);
      if (t < INF) times.erase({t, iv});
    }
    // crear nueva
    if (iu != *ans.begin() && iv != *ans.rbegin()) {
      it = ans.lower_bound(iu);
      it--;
      ju = *it;
      jv = *ans.upper_bound(iv);
      t = time(ju, jv);
      if (t < INF) times.insert({t, ju});
    }
    ans.erase(iu);
    ans.erase(iv);
  }
  cout << SZ(ans) << endl;
  for (auto &y : ans) cout << y + 1 << ' ';
  cout << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);

g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main f.cpp && for x in f*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done
*/