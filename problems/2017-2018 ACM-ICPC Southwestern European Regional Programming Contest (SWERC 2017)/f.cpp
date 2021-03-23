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

ll w, n, a, b, cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> w >> n;
  cnt = 0;
  forn(i, 0, n) {
    cin >> a >> b;
    cnt += a * b;
  }
  cout << cnt / w << endl;
}
