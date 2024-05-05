#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, char c) {
  vector<string> v;
  istringstream iss(s);
  string sub;
  // while (iss >> sub) {
  while (getline(iss, sub, c)) {
    v.push_back(sub);
  }
  return v;
}

int main() {
#ifdef LOCAL
  freopen("m.txt", "r", stdin);
  // freopen("h.out", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int t, n, c;
  double d, ans;
  string sn, sc;
  map<string, double> mp;
  vector<string> v;
  cin >> t;
  while (t--) {
    cin >> n >> c;
    mp.clear();
    for (int i = 0; i < n; i++) {
      cin >> sn >> sc;
      v = split(sc, '.');
      d = atoi(v[0].data());
      d = d + atoi(v[1].data()) * (1.0 / pow(10, v[1].size()));
      mp[sn] = d;
      // cout<<sn<<' '<<d<<endl;
    }
    ans = 0;
    for (int i = 0; i < c; i++) {
      cin >> sc >> sn;
      v = split(sc, '.');
      d = atoi(v[0].data());
      if (v.size() > 1)
        d = d + atoi(v[1].data()) * (1.0 / pow(10, v[1].size()));
      if (sn != "JD")
        ans += d * mp[sn];
      else
        ans += d;
      // cout<<sn<<' '<<d<<endl;
    }
    cout << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}
