class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
      if (nums.empty()) {
        return 0;
      }  

      unordered_map<int, int> blockCount;

      for (size_t i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            ++blockCount[nums[i]];
        }
      }

      int singleBlockCount = 0;
      for (const auto& entry : blockCount) {
        if (entry.second == 1) {
            ++singleBlockCount;
        }
      }

      return singleBlockCount;
    }
};