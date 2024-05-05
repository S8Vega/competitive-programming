#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long p[] = {257, 359};
long long mod[] = {1000000007, 1000000009};
long long X = 1000000010;

struct hashing {
  vector<long long> h[2], pot[2];
  int n;

  hashing(string s) {
    n = s.size();
    for (int i = 0; i < 2; ++i) {
      h[i].resize(n + 1);
      pot[i].resize(n + 1, 1);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        h[j][i] = (h[j][i - 1] * p[j] + s[i - 1]) % mod[j];
        pot[j][i] = (pot[j][i - 1] * p[j]) % mod[j];
      }
    }
  }
  // Hash del substring en el rango [i, j)
  long long hashValue(int i, int j) {
    j++;
    long long a =
        (h[0][j] - (h[0][i] * pot[0][j - i] % mod[0]) + mod[0]) % mod[0];
    long long b =
        (h[1][j] - (h[1][i] * pot[1][j - i] % mod[1]) + mod[1]) % mod[1];
    return a * X + b;
  }
};

int main() {
#ifdef LOCAL
  freopen("i.txt", "r", stdin);
  // freopen("h.out", "w", stdout);
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#endif
  int m = 11;
  char c[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
  map<char, int> mp;
  for (int i = 0; i < m; i++) mp[c[i]]++;
  int t, n, mx;
  string sn, si;
  cin >> t;
  while (t--) {
    cin >> sn;
    si = sn;
    reverse(si.begin(), si.end());
    hashing hn(sn);
    hashing hi(si);
    mx = 0;
    n = sn.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (mp[sn[j]] == 0) break;
        if (hn.hashValue(i, j) == hi.hashValue(n - j - 1, n - i - 1))
          mx = max(mx, j - i + 1);
      }
    }
    cout << mx << endl;
  }
  return 0;
}
