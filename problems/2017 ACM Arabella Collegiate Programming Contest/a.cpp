#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

const int N = 2e5 + 10;
int n, zerol[N], frq[N], sum1[N], sum2[N];
string s;

void solve() {
  cin >> n >> s;
  memset(frq, 0, sizeof(frq));
  memset(sum1, 0, sizeof(sum1));
  memset(sum2, 0, sizeof(sum2));
  long long ans = 0;
  int z = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      z++;
    else {
      zerol[i] = z;
      z = 0;
    }
  }
  z = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      z++;
    } else {
      ans += 1ll * z * zerol[i];
      z = 0;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') sum++;
    frq[sum]++;
  }
  sum1[1] = frq[1];
  sum2[2] = frq[2];
  for (int i = 3; i <= sum; i++) {
    if (i & 1) {
      sum1[i] = sum1[i - 2] + frq[i];
    } else {
      sum2[i] = sum2[i - 2] + frq[i];
    }
  }
  int nsum = 0;
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      nsum++;
      if (!(nsum & 1)) {
        int esum = sum;
        if (sum & 1) esum--;
        ans += 1ll * (sum2[esum] - sum2[nsum]) * (i - last);
      } else {
        int esum = sum;
        if (!(sum & 1)) esum--;
        ans += 1ll * (sum1[esum] - sum1[nsum]) * (i - last);
      }
      last = i;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}