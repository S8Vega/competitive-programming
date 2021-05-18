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
    ll integral = (ll)floor(input);
    double frac = input - double(integral);
    ll precision = 1e9;
    ll gcd = __gcd(ll(round(frac * double(precision))), precision);
    d = precision / gcd;
    u = ll(round(frac * double(precision)) / double(gcd));
    u += integral * d;
    gcd = __gcd(u, d);
    u /= gcd, d /= gcd;
  }

  string tostring() { return to_string(u) + " / " + to_string(d); }

  double todouble() { return double(u) / double(d); }

  void print() { cout << tostring() << endl; }

  Fraction operator+(const Fraction &fr) const {
    return Fraction(u * fr.d + d * fr.u, d * fr.d);
  }

  Fraction operator-(const Fraction &fr) const {
    return Fraction(u * fr.d - d * fr.u, d * fr.d);
  }

  Fraction operator*(const Fraction &fr) const {
    return Fraction(u * fr.u, d * fr.d);
  }

  Fraction operator/(const Fraction &fr) const {
    return Fraction(u * fr.d, d * fr.u);
  }

  bool operator<(const Fraction &fr) const { return u * fr.d < d * fr.u; }

  bool operator<=(const Fraction &fr) const { return u * fr.d <= d * fr.u; }

  bool operator>(const Fraction &fr) const { return u * fr.d > d * fr.u; }

  bool operator>=(const Fraction &fr) const { return u * fr.d >= d * fr.u; }

  bool operator==(const Fraction &fr) const { return u * fr.d == d * fr.u; }
};