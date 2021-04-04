#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("a.txt", "r", stdin);
  // freopen("b.txt", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int n;
  char c[] = {'W', 'B'};
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << c[(i + j) % 2];
    }
    cout << endl;
  }
  return 0;
}