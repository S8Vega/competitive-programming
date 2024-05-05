#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... E>
void debug(T t, E... e) {
  cout << t << (sizeof...(e) ? " " : "");
  debug(e...);
}
#define forn(i, a, b) for (int i = int(a); i < int(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 20;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << "20 20" << endl;
  string s[] = {
      "01111101111101110111", "11010011010011010101", "10110110110110110101",
      "01101101101101101101", "11011011011011011011", "10110110110110110110",
      "11101101101101101101", "10011011011011011001", "10110110110110110111",
      "01101101101101101101", "11011011011011011011", "10110110110110110110",
      "11101101101101101101", "10011011011011011001", "10110110110110110111",
      "01101101101101101101", "11011011011011011001", "10110110110110110111",
      "10100101100101100100", "11110111011111011111"};
  forn(i, 0, N) cout << s[i] << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main a.cpp && ./main < a.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/