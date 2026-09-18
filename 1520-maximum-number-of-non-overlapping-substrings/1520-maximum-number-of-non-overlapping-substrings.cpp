class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
     int n = s.length();
     vector<int> first(26, -1);
     vector<int> last(26, -1);

     for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        if (first[c] == -1) {
            first[c] = i;
        }
        last[c] = i;
     }   

     vector<pair<int, int>> intervals; // stores {end, start}

     for (int i = 0; i < 26; ++i) {
        if (first[i] == -1) {
            continue;
        }

        int l = first[i];
        int r = last[i];
        bool valid = true;

        for (int j = l; j <= r; ++j) {
            int c = s[j] - 'a';
            if (first[c] < l) {
                valid = false;
                break;
            }
            r = max(r, last[c]);
        }

        if (valid) {
            intervals.push_back({r, l});
        }
     }

     sort(intervals.begin(), intervals.end());

     vector<string> result;
     int lastEnd = -1;

     for (const auto& [r, l] : intervals) {
        if (l > lastEnd) {
            result.push_back(s.substr(l, r - l + 1));
            lastEnd = r;
        }
     }

     return result;
    }
};