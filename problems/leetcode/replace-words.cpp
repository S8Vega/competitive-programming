class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string, bool> dictionaryContain;
        for (string word: dictionary) dictionaryContain[word] = true;
        string ans = "", current = "";
        for (int i = 0; i < sentence.size(); i++) {
            current += sentence[i];
            if (sentence[i] == ' ') {
                ans += current;
                current = "";
                continue;
            }
            if (dictionaryContain[current]) {
                while (i < sentence.size() && sentence[i] != ' ') i++;
                i--;
            }
        }
        return ans + current;
    }
};