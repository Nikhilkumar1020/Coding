class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int step_cost = costs[i - 1];
            for (int j = max(0, i - 3); j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + step_cost + (i - j) * (i - j));
            }
        }

        return dp[n];
    }
};