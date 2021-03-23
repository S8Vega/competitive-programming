/*metodo que pasa un numero con decimales a una fraccion*/
// precision =  cantidad de decimales de precision
// pll es pair<long long,long long>
pll decimalTofraction(double input, ll precision = 3) {
  precision = pow(10, precision);
  double integral = floor(input);
  double frac = input - integral;
  ll gcd_ = __gcd((ll)round(frac * precision), precision);
  ll denominator = precision / gcd_;
  ll numerator = round(frac * precision) / gcd_;
  numerator += integral * denominator;
  ll gcdd = __gcd(numerator, denominator);
  numerator /= gcdd;
  denominator /= gcdd;
  // cout << numerator << " / " << denominator << endl;
  return {numerator, denominator};
}