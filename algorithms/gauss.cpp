/* resuelve sistemas de ecuaciones lineales y guarda las variables en ans,el
 *metodo retorna 0 si no hay solucion, 1 si hay una solucion o 2 si hay
 *multiples soluciones. ver el ejemplo en main para una mejor comprension*/

/*
input:
3 ecuaciones, 3 incognitas y una constante como respuesta, dicha constante se
guarda en la ultima columna de la matriz de vectores
3 4
3 2 -1 4
2 -1 1 3
1 3 2 13
lo anterior representa:
3x + 2y - z = 4
2x - y + z = 3
x + 3y + 2z = 13
*/

// O(min(n,m).nm) . In case n=m, the complexity is simply O(n3)

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 2;  // it doesn't actually have to be infinity or a big number

int gauss(vector<vector<double> > a, vector<double>& ans) {
  int n = (int)a.size();
  int m = (int)a[0].size() - 1;

  vector<int> where(m, -1);
  for (int col = 0, row = 0; col < m && row < n; ++col) {
    int sel = row;
    for (int i = row; i < n; ++i)
      if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
    if (abs(a[sel][col]) < EPS) continue;
    for (int i = col; i <= m; ++i) swap(a[sel][i], a[row][i]);
    where[col] = row;

    for (int i = 0; i < n; ++i)
      if (i != row) {
        double c = a[i][col] / a[row][col];
        for (int j = col; j <= m; ++j) a[i][j] -= a[row][j] * c;
      }
    ++row;
  }

  ans.assign(m, 0);
  for (int i = 0; i < m; ++i)
    if (where[i] != -1) ans[i] = a[where[i]][m] / a[where[i]][i];
  for (int i = 0; i < n; ++i) {
    double sum = 0;
    for (int j = 0; j < m; ++j) sum += ans[j] * a[i][j];
    if (abs(sum - a[i][m]) > EPS) return 0;
  }

  for (int i = 0; i < m; ++i)
    if (where[i] == -1) return INF;
  return 1;
}

int main() {
#ifdef LOCAL
  freopen("main.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  vector<double> ans, aux;
  vector<vector<double> > a;
  int n, m;
  double x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    aux.clear();
    for (int j = 0; j < m; j++) {
      cin >> x;
      aux.push_back(x);
    }
    a.push_back(aux);
  }
  cout << gauss(a, ans) << endl;
  // imprime las respuestas guardadas en ans
  for (auto r : ans) cout << r << ' ';
  cout << endl;
  return 0;
}