class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_val = nums.back();
        vector<int> dp(max_val + 2, 0);
        int ans = 0;

        for (int num : nums) {
            dp[num + 1] = dp[num] + 1;
            dp[num] = dp[num - 1] + 1;
            ans = max(ans, max(dp[num], dp[num + 1]));
        }

        return ans;
    }
};