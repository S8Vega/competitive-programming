#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = 1;
    ll arr[10];
    memset(arr, 0, sizeof arr);

    while (a * x * x + b * x <= n) {
      string s = to_string(a * x * x + b * x);
      int mx1 = 0;
      unordered_map<ll, int> mp;
      for (int i = 0; i < s.size(); i++) {
        mp[s[i] - '0']++;
        mx1 = max(mx1, mp[s[i] - '0']);
      }
      for (auto k : mp) {
        if (k.second == mx1) {
          arr[k.first]++;
        }
      }
      x++;
    }
    int ans = -1;
    ll mx = 0;
    for (int i = 0; i < 10; i++) {
      if (arr[i] > mx) {
        mx = arr[i];
        ans = i;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
