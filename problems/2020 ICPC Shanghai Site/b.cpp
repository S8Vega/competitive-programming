#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n, m;
string a[N], b[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  forn(i, 0, n) cin >> a[i];
  forn(i, 0, n) cin >> b[i];
  int cnt = 0, dif = 0;
  forn(i, 0, n) {
    forn(j, 0, m) {
      if (a[i][j] == b[i][j])
        cnt++;
      else
        dif++;
    }
  }
  if (cnt > dif) {
    forn(i, 0, n) cout << a[i] << endl;
    return 0;
  }
  forn(i, 0, n) {
    forn(j, 0, m) {
      if (a[i][j] == '.')
        cout << 'X';
      else
        cout << '.';
    }
    cout << endl;
  }
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main b.cpp && ./main < b.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/