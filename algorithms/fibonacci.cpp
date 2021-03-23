/*varias formas de calcular fibonacci*/

/*If n is even then k = n/2:
F(n) = [2*F(k-1) + F(k)]*F(k)

If n is odd then k = (n + 1)/2
F(n) = F(k)*F(k) + F(k-1)*F(k-1) */

const int MAX = 1000;

ll f[MAX] = {0};

ll fib(int n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return (f[n] = 1);
  if (f[n]) return f[n];
  ll k = (n & 1) ? (n + 1) / 2 : n / 2;
  f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                 : (2 * fib(k - 1) + fib(k)) * fib(k);

  return f[n];
}

ll fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

static BigInteger fib(int n) {
  BigInteger a = BigInteger.valueOf(0);
  BigInteger b = BigInteger.valueOf(1);
  BigInteger c = BigInteger.valueOf(1);
  for (int j = 2; j <= n; j++) {
    c = a.add(b);
    a = b;
    b = c;
  }
  return (a);
}