#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
  // your code goes here

  ios::sync_with_stdio(0), cin.tie(0);

  int s;
  cin >> s;
  pair<string, string> sts[s];

  for (int i = 0; i < s; i++) {
    cin >> sts[i].second;
    cin >> sts[i].first;
  }
  sort(sts, sts + s);

  for (int i = 0; i < s; i++) {
    cout << sts[i].second << " " << sts[i].first << endl;
  }
  return 0;
}