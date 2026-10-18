class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < m; ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left) % MOD;
        long long right_ways = dfs(right) % MOD;

        return (((comb[m - 1][left.size()] * left_ways) % MOD) * right_ways) % MOD;
    }

    public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};