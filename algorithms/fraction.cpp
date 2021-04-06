// estructura para hacer operaciones entre fracciones

struct Fraction {
  ll n, d;
  Fraction(ll _num = 0, ll _den = 1) {
    n = _num;
    d = _den;
  }
  Fraction operator+(const Fraction &b) {
    fr c;
    c.n = (n * b.d) + (d * b.n);
    c.d = d * b.d;
    ll g = __gcd(c.n, c.d);
    c.n /= g, c.d /= g;
    return c;
  }
  Fraction operator/(Fraction &b) {
    fr c;
    c.n = n * b.d;
    c.d = d * b.n;
    ll g = __gcd(c.n, c.d);
    c.n /= g, c.d /= g;
    return c;
  }
};