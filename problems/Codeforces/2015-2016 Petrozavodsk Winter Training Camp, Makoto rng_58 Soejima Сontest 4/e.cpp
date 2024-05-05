#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... E>
void debug(T t, E... e) {
  cout << t << (sizeof...(e) ? " " : "");
  debug(e...);
}
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;
int n, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, 0, n) cin >> a[i];
  sort(a, a + n);
  ll ans = 0, sum = 0;
  forn(i, 0, n) {
    if (sum < a[i]) {
      sum += a[i];
      ans++;
    }
  }
  cout << ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/