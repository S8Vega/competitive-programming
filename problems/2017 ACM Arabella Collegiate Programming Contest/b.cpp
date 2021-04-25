#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
  // freopen("mainout.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (b > a)
      cout << "WeWillEatYou" << endl;
    else
      cout << "FunkyMonkeys" << endl;
  }
  return 0;
}
