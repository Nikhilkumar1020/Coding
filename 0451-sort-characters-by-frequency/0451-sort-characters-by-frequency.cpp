class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> mp;

    for (char c : s) {
        mp[c]++;
    }

    vector<pair<char, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string ans;

    for (auto &p : v) {
        ans += string(p.second, p.first);
    }

    return ans;
    }
};