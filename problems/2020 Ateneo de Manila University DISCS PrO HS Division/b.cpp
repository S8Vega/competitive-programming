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

const ll MOD = 104206969;
ll meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll anio;

ll format(ll mes, ll dia) {
  if (dia < 10) {
    return mes * 10 + dia;
  }
  return mes * 100 + dia;
}

ll l, r;

ll getbis(ll x) {
  if (!x) return 0;
  ll ans = x / 4 - x / 100;
  return ans % MOD;
}

void solve() {
  anio = 0;
  for (ll mes = 1; mes <= 12; mes++) {
    for (ll dia = 1; dia <= meses[mes - 1]; dia++) {
      anio = (anio + format(mes, dia)) % MOD;
    }
  }
  ll bisiesto = format(2, 29);
  ll x = (getbis(r) - getbis(l) + MOD) % MOD;
  ll ans = (anio * ((r - l + 1) % MOD) % MOD + (x * bisiesto) % MOD) % MOD;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> r;
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