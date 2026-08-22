class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char, int> lastSeen;
     int left = 0;
     int bestLength = 0;

     for (int right = 0; right < s.size(); right++) {
        char current = s[right];

        if (lastSeen.count(current)) {
            left = max(left, lastSeen[current] + 1);
        }

        lastSeen[current] = right;
        bestLength = max(bestLength, right - left + 1);
     }   

     return bestLength;
    }
};