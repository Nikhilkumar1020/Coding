class Solution {
    void dfs(int index, int left_rem, int right_rem, int balance, const string& s, string& current, vector<string>& result) {
        if (index == s.size()) {
            if (left_rem == 0 && right_rem == 0 && balance == 0) {
                result.push_back(current);
            }
            return;
        }

        char c = s[index];

        if (c == '(' && left_rem > 0) {
            int next_index = index;
            while (next_index < s.size() && s[next_index] == '(') {
                next_index++;
            }
            dfs(index + 1, left_rem - 1, right_rem, balance, s, current, result);
        } else if (c == ')' && right_rem > 0) {
            dfs(index + 1, left_rem, right_rem - 1, balance, s, current, result);
        }

        current.push_back(c);

        if (c != '(' && c != ')') {
            dfs(index + 1, left_rem, right_rem, balance, s, current, result);
        } else if (c == '(') {
            dfs(index + 1, left_rem, right_rem, balance + 1, s, current, result);
        } else if (balance > 0) {
            dfs(index + 1, left_rem, right_rem, balance - 1, s, current, result);
        }

        current.pop_back();
    }

    void backtrack(int index, int left_rem, int right_rem, int open, const string& s, string& expr, unordered_set<string>& result) {
        if (index == s.size()) {
            if (left_rem == 0 && right_rem == 0 && open == 0) {
                result.insert(expr);
            }
            return;
        }

        char c = s[index];

        if ((c == '(' && left_rem > 0) || (c == ')' && right_rem > 0)) {
        backtrack(index + 1, left_rem - (c == '('), right_rem - (c == ')'), open, s, expr, result);
    }

    expr.push_back(c);

    if (c != '(' && c != ')') {
        backtrack(index + 1, left_rem, right_rem, open, s, expr, result);
    } else if (c == '(') {
        backtrack(index + 1, left_rem, right_rem, open + 1, s, expr, result);
    } else if (open > 0) {
        backtrack(index + 1, left_rem, right_rem, open - 1, s, expr, result);
    }

    expr.pop_back();
};

public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0;
        int right_rem = 0;

        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--;
                } else {
                    right_rem++;
                }
            }
        }

        unordered_set<string> valid_set;
        string expr = "";
        backtrack(0, left_rem, right_rem, 0, s, expr, valid_set);

        return vector<string>(valid_set.begin(), valid_set.end());
    }
};