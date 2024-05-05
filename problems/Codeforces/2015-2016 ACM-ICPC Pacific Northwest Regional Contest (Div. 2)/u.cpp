#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define db(x) #x << " = " << x << " | "

struct fr {
  ll n, d;
  fr(ll _num = 0, ll _den = 1) {
    n = _num;
    d = _den;
  }
  fr operator+(const fr &b) {
    fr c;
    c.n = (n * b.d) + (d * b.n);
    c.d = d * b.d;
    ll g = __gcd(c.n, c.d);
    c.n /= g, c.d /= g;
    return c;
  }
  fr operator/(fr &b) {
    fr c;
    c.n = n * b.d;
    c.d = d * b.n;
    ll g = __gcd(c.n, c.d);
    c.n /= g, c.d /= g;
    return c;
  }
};

const int MAX = 105;
ll y, x, r;
fr g[MAX][MAX];
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void fx(int &_y, int &_x) {
  bool f = false;
  if (_y == 2 && _x == 0) f = true;
  if (_y == -1 && _x == -1) {
    _y = y - 1, _x = x - 1;
  } else if (_y == -1 && _x == x) {
    _y = y - 1, _x = 0;
  } else if (_y == y && _x == -1) {
    _y = 0, _x = x - 1;
  } else if (_y == y && _x == x) {
    _y = 0, _x = 0;
  } else if (_y == -1) {
    _y = y - 1;
  } else if (_y == y) {
    _y = 0;
  } else if (_x == -1) {
    _x = x - 1;
  } else if (_x == x) {
    _x = 0;
  }
}

int main() {
#ifdef LOCAL
  freopen("u.txt", "r", stdin);
  // freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  cin >> x >> y >> r;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      cin >> g[i][j].n;
      g[i][j].d = 1;
    }
  }
  fr sg[MAX][MAX];
  fr den, aux;
  den.n = 9, den.d = 1;
  int _y, _x;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < x; k++) {
        aux = g[j][k];
        for (int l = 0; l < 8; l++) {
          _y = j + dy[l], _x = k + dx[l];
          fx(_y, _x);
          aux = aux + g[_y][_x];
        }
        sg[j][k] = aux / den;
      }
    }
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < x; k++) g[j][k] = sg[j][k];
    }
  }
  set<pll> st;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      // cout << g[i][j].n << '/' << g[i][j].d << ' ';
      st.insert({g[i][j].n, g[i][j].d});
    }
    // cout << endl;
  }
  cout << st.size() << endl;
  return 0;
}