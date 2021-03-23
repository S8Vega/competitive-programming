/* cantidad de formas diferentes de ir de un nodo u a un nodo v pasando por k
aristas usando dp de forma button up y top down */

const int MAX = 25;
int n;
bool g[MAX][MAX];

int dfs(int u, int v, int k) {
  int count[n][n][k + 1];
  for (int e = 0; e <= k; e++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        count[i][j][e] = 0;
        if (e == 0 && i == j) count[i][j][e] = 1;
        if (e == 1 && g[i][j]) count[i][j][e] = 1;
        if (e > 1) {
          for (int a = 0; a < n; a++)
            if (g[i][a]) count[i][j][e] += count[a][j][e - 1];
        }
      }
    }
  }
  return count[u][v][k];
}

// MAX1: cantidad de nodos, MAX2: k aristas
const int MAX1 = 25, MAX2 = 10005;
int dp[MAX1][MAX1][MAX2];
// u: nodo inicio, v: nodo destino, k: pasando por k aristas
int f(int u, int v, int k) {
  if (dp[u][v][k]) return dp[u][v][k];
  if (k == 1 && g[u][v]) return 1;
  for (int a = 0; a < n; a++)  // ir de u a v pasando por a
    if (g[u][a]) dp[u][v][k] += f(a, v, k - 1);
  return dp[u][v][k];
}