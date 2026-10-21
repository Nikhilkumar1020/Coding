class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n <= 2) {
            return -1;
        }

        char min_char = s[0];
        char max_char = s[0];
        for (char c : s) {
            min_char = min(min_char, c);
            max_char = max(max_char, c);
        }

        if (s[0] == min_char || s.back() == max_char) {
            return 1;
        }

        bool min_not_at_end = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == min_char) {
                min_not_at_end = true;
                break;
            }
        }

        bool max_not_at_start = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == max_char) {
                max_not_at_start = true;
                break;
            }
        }

        if (min_not_at_end || max_not_at_start) {
            return 2;
        }

        return 3;
    }
};