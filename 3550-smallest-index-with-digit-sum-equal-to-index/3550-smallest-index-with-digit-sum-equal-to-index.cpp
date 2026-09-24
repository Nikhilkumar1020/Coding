class Solution {
public:
    int smallestIndex(vector<int>& nums) {
      int n = nums.size();

      for (int i = 0; i < n; ++i) {
        int val = nums[i];
        int sumDigits = 0;

        while (val > 0) {
            sumDigits += val % 10;
            val /= 10;
        }

        if (sumDigits == i) {
            return i;
        }
      }  

      return -1;
    }
};