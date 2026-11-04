class Solution {
    vector<long long> getMinOps(const vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> minOps;
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;

        for (int i = 0; i < n; ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }

            if (i >= x) {
                int outNum = nums[i - x];
                auto it = lower.find(outNum);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= outNum;
                } else {
                    upper.erase(upper.find(outNum));
                    upperSum -= outNum;
                }
            }

            while (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(val);
                upperSum -= val;
                lowerSum += val;
            }

            while (lower.size() > upper.size() + 1) {
                auto it = prev(lower.end());
                int val = *it;
                lower.erase(it);
                upper.insert(val);
                lowerSum -= val;
                upperSum += val;
            }

            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long cost = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                minOps.push_back(cost);
            }
        }
        return minOps;
    }

    public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> ops = getMinOps(nums, x);

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = n - x; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i + 1][j]; 
                if (dp[i + x][j - 1] != 1e18) {
                    dp[i][j] = min(dp[i][j], ops[i] + dp[i + x][j - 1]);
                }
            }
        }

        return dp[0][k];
    }
};