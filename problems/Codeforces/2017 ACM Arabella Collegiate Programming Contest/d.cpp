#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i != 0 && abs(arr[i] - arr[i - 1]) % 2) {
        ok = 0;
      }
    }
    if (ok)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
