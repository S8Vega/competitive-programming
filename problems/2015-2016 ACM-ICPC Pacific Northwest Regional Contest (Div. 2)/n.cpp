#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, p, ma = 1, me = 1000, num;
  string tmp;
  cin >> h >> p;
  me = p;

  while (h--) {
    cin >> num >> tmp;
    if (tmp == "SAFE")
      ma = max(ma, num);
    else
      me = min(me, num);
  }

  int mm = me, nn = ma;
  me = nn + 1;
  ma = mm - 1;

  cout << me << " " << ma << endl;

  return 0;
}