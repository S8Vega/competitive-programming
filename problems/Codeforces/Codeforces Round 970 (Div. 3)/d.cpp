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

struct dsu {
  vector<int> par, sz;
  int size;  // Cantidad de conjuntos

  dsu(int n) : par(n), sz(n, 1) {
    size = n;
    iota(par.begin(), par.end(), 0);
  }
  // Busca el nodo representativo del conjunto de u
  int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }
  // Une los conjuntos de u y v
  void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
    size--;
  }
  // Retorna la cantidad de elementos del conjunto de u
  int count(int u) { return sz[find(u)]; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), ans(n, 0);
  for (int &x : a) {
    cin >> x;
    x--;
  }
  string s;
  cin >> s;
  forn(i, 0, n) ans[i] = s[i] == '0';

  dsu d(n);
  int aux, ch;
  forn(i, 0, n) {
    ch = 0;
    if (d.find(i) != d.find(a[i])) {
      aux = ans[d.find(i)] + ans[d.find(a[i])];
      ch = 1;
    }
    d.unite(i, a[i]);
    if (ch) ans[d.find(i)] = aux;
  }
  // forn(i, 0, n) dbg(i, d.find(i), ans[d.find(i)]);
  forn(i, 0, n) cout << ans[d.find(i)] << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
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

Linux command
g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra
-D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo
====================$x=================; time -p ./main <$x; echo
===========================================; done

Powershell command
cd $dir && g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -o
main $fileName && $testcase = '>>> name'; foreach ($file in Get-ChildItem
$fileNameWithoutExt*.txt) { echo  $testcase.Replace('name', $file.Name);
Get-Content $file.Name | ./main; echo
==========================================; }
*/