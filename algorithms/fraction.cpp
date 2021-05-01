// estructura para hacer operaciones entre fracciones

struct Fraction {
  ll u, d;

  Fraction(ll _u = 0, ll _d = 1) {
    u = _u, d = _d;
    if (d) {
      ll g = __gcd(abs(u), abs(d));
      u /= g, d /= g;
      if (d < 0) u = -u, d = -d;
    } else
      u = 1;
  }

  Fraction(double input) {
    double integral = floor(input);
    double frac = input - integral;

    const ll precision = 1000000000;  // This is the accuracy.

    ll gcd_ = gcd(round(frac * precision), precision);

    d = precision / gcd_;
    u = round(frac * precision) / gcd_;
  }

  void print() { cout << u << '/' << d << endl; }

  Fraction operator+(const Fraction &f) const {
    return Fraction(u * f.d + d * f.u, d * f.d);
  }

  Fraction operator-(const Fraction &f) const {
    return Fraction(u * f.d - d * f.u, d * f.d);
  }

  Fraction operator*(const Fraction &f) const {
    return Fraction(u * f.u, d * f.d);
  }

  Fraction operator/(const Fraction &f) const {
    return Fraction(u * f.d, d * f.u);
  }

  Fraction operator<(const Fraction &f) const { return u * f.d < d * f.u; }

  Fraction operator<=(const Fraction &f) const { return u * f.d <= d * f.u; }

  Fraction operator>(const Fraction &f) const { return u * f.d > d * f.u; }

  Fraction operator>=(const Fraction &f) const { return u * f.d >= d * f.u; }

  Fraction operator==(const Fraction &f) const { return u * f.d == d * f.u; }
};