#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("e.txt", "r", stdin);
  // freopen("mainout.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 2 || n == 3)
      cout << "second" << endl;
    else
      cout << "first" << endl;
  }
  return 0;
}
