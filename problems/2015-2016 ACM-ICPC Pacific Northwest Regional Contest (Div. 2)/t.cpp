#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
bool valid(int a, int b, int c) { return a * a + b * b == c * c; }
int main() {
#ifdef LOCAL
  freopen("m.txt", "r", stdin);
  // freopen("main.txt","w",stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif

  vector<int> a(3), b(3);
  cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (a == b && (valid(a[0], a[1], a[2]) || valid(a[0], a[2], a[1]) ||
                 valid(a[1], a[2], a[0])))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}