#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

void solve() {
  int n;
  cin >> n;

  vector<int> num(n);
  for (auto &x : num) cin >> x;

  sort(num.begin(), num.end());

  long long step = 0, cnt = 0;
  bool win = true;

  for (int i = 0; i < n; ++i) {
    if (num[i] == num[i + 1]) cnt++;
    if (i < n - 2 && num[i] == num[i + 1] && num[i + 1] == num[i + 2])
      win = false;
    if (i < n - 2 && num[i] + 1 == num[i + 1] && num[i + 1] == num[i + 2])
      win = false;
    if (num[i] < i) win = false;
    if (cnt >= 2) win = false;
  }

  if (!win) {
    cout << "cslnb" << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      step += num[i] - i;
    }

    if (step & 1)
      cout << "sjfnb" << endl;
    else
      cout << "cslnb" << endl;
  }
}

int main() {
#ifdef LOCAL
  freopen("d.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  solve();
  return 0;
}
/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp -DLOCAL && ./main
*/