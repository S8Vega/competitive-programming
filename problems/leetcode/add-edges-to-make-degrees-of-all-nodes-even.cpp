class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    vector<unordered_set<int>> v(n + 1);
    for (auto& i : edges) {
      v[i[0]].insert(i[1]);
      v[i[1]].insert(i[0]);
    }
    vector<int> o;
    for (int i = 1; i <= n; i++) {
      if (v[i].size() % 2 == 1) {
        o.push_back(i);
      }
    }
    if (o.size() == 2) {
      for (int i = 1; i <= n; i++) {
        if (v[o[0]].count(i) == 0 && v[o[1]].count(i) == 0) return true;
      }
    }
    if (o.size() == 4) {
      return ((v[o[0]].count(o[1]) == 0 && v[o[2]].count(o[3]) == 0) ||
              (v[o[0]].count(o[2]) == 0 && v[o[1]].count(o[3]) == 0) ||
              (v[o[0]].count(o[3]) == 0 && v[o[1]].count(o[2]) == 0));
    }
    return o.size() == 0;
  }
};