class Solution {
public:
    string reverseParentheses(string s) {
      int n = s.size();
      vector<int> pair(n);
      vector<int> stack;

      for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stack.push_back(i);
        } else if (s[i] == ')' ){
            int j = stack.back();
            stack.pop_back();
            pair[i] = j;
            pair[j] = i;
        }
      }  

      string result = "";
      result.reserve(n);
      for (int i = 0, dir = 1; i < n; i += dir) {
        if (s[i] == '(' || s[i] == ')') {
            i = pair[i];
            dir = -dir;
        } else {
        result += s[i];
      }
    }

     return result;
    }
};