class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> indexOf;
        for(int idx = 0; idx < (int)nums.size(); ++idx){
            int complement = target - nums[idx];

            auto it = indexOf.find(complement);
            if(it != indexOf.end()) {
                return {it->second, idx};
            }

            indexOf[nums[idx]] = idx;
        }
        return {};
    }
};