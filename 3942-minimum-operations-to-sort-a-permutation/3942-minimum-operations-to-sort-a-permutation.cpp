class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n = nums.size();
       if (n <= 1) return 0;

       int zero = -1;
       bool is_inc = true;
       bool is_dec = true;

       for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            zero = i;
        }
        if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
            is_inc = false;
        }
        if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
            is_dec = false;
        }
       }

       int ans = 1e9;

       if (is_inc) {
        ans = min(ans, zero);
        ans = min(ans, n - zero + 2);
       }

       if (is_dec) {
        ans = min(ans, zero + 2);
        ans = min(ans, n - zero);
       }

       return ans == 1e9 ? -1 : ans;
    }
};