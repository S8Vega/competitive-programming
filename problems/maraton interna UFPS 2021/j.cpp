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

const int MAX_N = 10010;
const int MAX_W = 1000010;
int gold[MAX_N];
int weight[MAX_N];
int n, w;

int dp_opt[2][MAX_W + 5];
void mochila_opt() {
  for (int i = 0; i <= MAX_W; i++) dp_opt[n % 2][i] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int w = 0; w <= MAX_W; w++) {
      dp_opt[i % 2][w] = dp_opt[(i + 1) % 2][w];
      if (w - weight[i] >= 0)
        dp_opt[i % 2][w] =
            max(dp_opt[i % 2][w], dp_opt[(i + 1) % 2][w - weight[i]] + gold[i]);
    }
  }
}

void solve() {
  cin >> n >> w;
  forn(i, 0, n) cin >> weight[i] >> gold[i];
  mochila_opt();
  cout << dp_opt[0][w] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

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