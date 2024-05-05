#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    ll g = arr[0];
    for (int i = 1; i < n; i++) {
      g = __gcd(arr[i], g);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += g * (((arr[i]) + g - 1) / g);
    }
    cout << ans << " " << g << endl;
  }
  return 0;
}
