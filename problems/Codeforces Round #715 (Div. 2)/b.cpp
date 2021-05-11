#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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

int n;
string s;
vector<int> ps;

bool eval_l(int &res) {
  res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'T') continue;
    res++;
    // dbg(i, res, ps[i]);
    if (res > ps[i]) return false;
  }
  return true;
}

bool eval_r(int &res) {
  // dbg("r");
  int aux = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'T') continue;
    res++, aux++;
    if (ps[n - 1] - ps[i] < aux) return false;
    ;
    // dbg(i, res, ps[i]);
  }
  return res == ps[n - 1];
}

void solve() {
  cin >> n >> s;
  ps = vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    ps[i] = s[i] == 'T';
  }
  for (int i = 1; i < n; i++) ps[i] += ps[i - 1];
  // cout << s << endl;
  // for (int i = 0; i < n; i++) cout << ps[i] << ' ';
  // cout << endl;
  int res;
  if (eval_l(res) && eval_r(res))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
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