class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
      vector<long long> ans(k, 0);
      vector<long long> dp(k, 0);

      for (int num : nums) {
        int v = num % k;
        vector<long long> next_dp(k, 0);

        next_dp[v] += 1;

        for (int r = 0; r < k; ++r) {
            if (dp[r] > 0) {
                int newRem = (1LL * r * v) % k;
                next_dp[newRem] += dp[r];
            }
        }

        for (int r = 0; r < k; ++r) {
            ans[r] += next_dp[r];
        }

        dp = move(next_dp);
      }  

      return ans;
    }
};