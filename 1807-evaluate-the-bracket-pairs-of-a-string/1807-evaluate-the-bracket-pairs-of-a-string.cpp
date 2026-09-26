class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
      unordered_map<string, string> dict;
      for (const auto& pair : knowledge) {
        dict[pair[0]] = pair[1];
      }  

      string result;
      int n = s.size();

      for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            int start = ++i;
            while (i < n && s[i] != ')') {
                ++i;
            }
            string key = s.substr(start, i - start);
            auto it = dict.find(key);
            if (it != dict.end()) {
                result += it->second;
            } else {
                result += '?';
            }
        } else {
        result += s[i];}
      }

    return result;
    }
};