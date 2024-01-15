typedef long long ll;

class Solution {
 public:
  vector<int> ans;

  int cantDigits(int n) {
    int cant = 0;
    while (n > 0) {
      n /= 10;
      cant++;
    }
    return cant;
  }

  void f(int n, int k, int cur, int next) {
    cout << "- " << cur << ' ' << next << endl;
    if (next > 9 || next < 0) return;
    cur = cur * 10LL + next;
    if (cantDigits(cur) == n) {
      cout << cur << ' ' << next << endl;
      ans.push_back(cur);
      return;
    }
    f(n, k, cur, next - k);
    f(n, k, cur, next + k);
  }

  vector<int> numsSameConsecDiff(int n, int k) {
    ans.clear();
    for (int i = 1; i <= 9; i++) {
      f(n, k, 0, i);
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};