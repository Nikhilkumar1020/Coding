class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        unordered_map<int, int> lastSeen;
        int left = 0;
        int maxLen = 2;

        for (int right = 0; right < n; ++right) {
            int val = nums[right];

            for (int p = 2; p * p <= val; ++p) {
                if (val % p == 0) {
                    if (lastSeen.count(p)) {
                        left = max(left, lastSeen[p] + 1);
                    }
                    lastSeen[p] = right;
                    while (val % p == 0) {
                        val /= p;
                    }
                }
            }

            if (val > 1) {
                if (lastSeen.count(val)) {
                    left = max(left, lastSeen[val] + 1);
                }
                lastSeen[val] = right;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};