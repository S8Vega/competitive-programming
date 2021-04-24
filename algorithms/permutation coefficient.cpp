
ll npr(ll n, ll k) {
  ll p = 1;
  for (int i = 0; i < k; i++) p = (p * (n - i)) % MOD;
  return p;
}