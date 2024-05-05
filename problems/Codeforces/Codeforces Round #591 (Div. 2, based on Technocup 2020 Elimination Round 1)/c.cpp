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

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

void solve() {
  ll n, x, a, y, b, k;
  cin >> n;
  vector<ll> P(n);
  for (int i = 0; i < n; ++i) cin >> P[i];
  sort(P.begin(), P.end(), greater<int>());
  cin >> x >> a >> y >> b >> k;
  if (x < y) {
    swap(x, y);
    swap(a, b);
  }
  ll aux = 0;
  ll cab = n / lcm(a, b), ca = n / a, cb = n / b;
  ca -= cab, cb -= cab;
  int ind = 0;
  for (int i = 0; i < cab; ++i, ++ind) aux += (P[ind] / 100) * (x + y);
  for (int i = 0; i < ca; ++i, ++ind) aux += (P[ind] / 100) * x;
  for (int i = 0; i < cb; ++i, ++ind) aux += (P[ind] / 100) * y;
  if (aux < k) {
    cout << -1 << endl;
    return;
  }
  ll low = 1, high = n;

  while (low < high) {
    ll mid = (low + high) / 2;
    ll total = 0;
    cab = mid / lcm(a, b), ca = mid / a, cb = mid / b;
    ca -= cab, cb -= cab;
    ind = 0;
    for (int i = 0; i < cab; ++i, ++ind) total += (P[ind] / 100) * (x + y);
    for (int i = 0; i < ca; ++i, ++ind) total += (P[ind] / 100) * x;
    for (int i = 0; i < cb; ++i, ++ind) total += (P[ind] / 100) * y;
    if (total >= k)
      high = mid;
    else
      low = mid + 1;
    aux = max(aux, total);
  }
  cout << high << endl;
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