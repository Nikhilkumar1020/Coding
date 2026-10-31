class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<pair<int, int>> dp(n + 1, {0, 0});
        dp[1] = {1, 1}; 

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int paths_from_above = dp[c + 1].second;
                    int paths_from_left = dp[c].first;
                    dp[c + 1] = {paths_from_above, paths_from_left};
                } else {
                    int total = (dp[c + 1].second + dp[c].first) % MOD;
                    dp[c + 1] = {total, total};
                }
            }
        }

        return dp[n].first;
    }
};