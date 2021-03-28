#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <typename T, typename... Args>
void debug(T a, Args... args) {
  cout << a << " ";
  debug(args...);
}
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

ll n, sum, x;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  sum = 0;
  forn(i, 0, n) {
    cin >> x;
    sum += x;
  }
  if (sum % 3)
    cout << "no" << endl;
  else
    cout << "yes" << endl;
}

/*
g++ -pthread -Wall -Wshadow -std=c++17 -o main d.cpp && ./main < d.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
*/