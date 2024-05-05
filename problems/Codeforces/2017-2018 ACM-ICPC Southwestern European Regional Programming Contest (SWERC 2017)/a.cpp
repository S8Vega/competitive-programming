#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T x, Args... args) {
  cout << x << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int n1, n2;
vector<int> v1, v2;
map<int, int> rep;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n1 >> n2;
  v1.resize(n1);
  v2.resize(n2);
  forn(i, 0, n1) cin >> v1[i];
  forn(i, 0, n2) cin >> v2[i];
  forn(i, 0, n1) {
    forn(j, 0, n2) {
      if (v2[j] > v1[i]) rep[v2[j] - v1[i]]++;
    }
  }
  int ans = -1;
  rep[ans] = 0;
  for (auto x : rep) {
    if (x.S > rep[ans]) ans = x.F;
  }
  if (ans == -1) ans = 0;
  cout << ans << endl;
}
