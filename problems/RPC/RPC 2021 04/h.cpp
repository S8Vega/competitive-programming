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
#define SZ(v) ((int)(v.size()))
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int n;
stack<int> st;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int ans = 0, x, sz;
  forn(i, 0, n) {
    cin >> x;
    sz = SZ(st);
    while (SZ(st) && st.top() < x) st.pop();
    ans += min(sz, sz - SZ(st) + 1);
    st.push(x);
  }
  cout << ans << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main h.cpp && ./main < h.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/