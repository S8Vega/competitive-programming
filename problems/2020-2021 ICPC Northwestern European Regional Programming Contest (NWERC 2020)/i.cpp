#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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

struct Rango {
  int l, r;
  bool intersecta(Rango &o) { return min(r, o.r) > max(l, o.l); }
};

const int N = 410, M = 3;
int n, d[N], t[M][N];
bool ans[M][N][N];
vector<Rango> rango[M][N];

void init(int id, int inicio) {
  rango[id][inicio] = vector<Rango>(n);
  int tiempo = 0;
  for (int i = inicio, j = 0; j < n; j++, i = (i + 1) % n) {
    rango[id][inicio][i].l = tiempo;
    rango[id][inicio][i].r = tiempo + t[id][i];
    tiempo += t[id][i] + d[i];
  }
}

bool intersectan(int id_u, int id_v, int i, int j) {
  for (int k = 0; k < n; k++) {
    if (rango[i][id_u][k].intersecta(rango[j][id_v][k])) return true;
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < n; j++) cin >> t[i][j];
  }
  for (int id = 0; id < M; id++) {
    for (int inicio = 0; inicio < n; inicio++) init(id, inicio);
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (!intersectan(j, k, i, (i + 1) % M)) ans[i][j][k] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (ans[0][i][j] && ans[1][j][k] && ans[2][k][i]) {
          cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
          return;
        }
      }
    }
  }
  cout << "Impossible" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}