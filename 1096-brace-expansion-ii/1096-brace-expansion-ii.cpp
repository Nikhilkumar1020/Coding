class Solution {
    vector<string> multiply(const vector<string>& a, const vector<string>& b) {
        vector<string> res;
        res.reserve(a.size() * b.size());
        for (const string& s1 : a) {
            for (const string& s2 : b) {
                res.push_back(s1 + s2);
            }
        }
        return res;
    }

    vector<string> parse(const string& s, int& i) {
        vector<vector<string>> sum_groups;
        vector<string> cur_prod = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                sum_groups.push_back(cur_prod);
                cur_prod = {""};
                ++i;
            } else if (s[i] == '{') {
                ++i;
                vector<string> inner = parse(s, i);
                ++i;
                cur_prod = multiply(cur_prod, inner);
            }else {
            string word = "";
            while (i < s.size() && isalpha(s[i])) {
            word += s[i++];
        }
        cur_prod = multiply(cur_prod, {word});
    }
}

    sum_groups.push_back(cur_prod);

    vector<string> total;
    for (const auto& group : sum_groups) {
        for (const string& str : group) {
             total.push_back(str);
        }
    }

    sort(total.begin(), total.end());
    total.erase(unique(total.begin(), total.end()), total.end());
    return total;
    }

public:
    vector<string> braceExpansionII(string expression) {
    int i = 0;
    return parse(expression, i);
    }
};