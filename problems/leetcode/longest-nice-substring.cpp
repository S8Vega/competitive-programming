class Solution {
public:

    bool isValid(string s) {
        unordered_map<char, bool> mp;
        for (char c: s) {
            mp[c] = true;
        }
        for (auto p: mp) {
            if (!mp[toupper(p.first)] || !mp[tolower(p.first)])
                return false;
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            string cur = "";
            for (int j = i; j < s.size(); j++) {
                cur += s[j];
                if (cur.size() > ans.size() && isValid(cur)) 
                    ans = cur;
            }
        }
        return ans;
    }
};