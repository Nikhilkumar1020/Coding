class Solution {
    public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum_k = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool valid = true;
            int prev_max = -1;

            for (int b = 0; b < n / k; ++b) {
                int start = b * k;
                int drops = 0;
                int drop_idx = -1;

                for (int i = 0; i < k; ++i) {
                    int curr = nums[start + i];
                    int next = nums[start + (i + 1) % k];
                    if (curr > next) {
                        drops++;
                        drop_idx = i;
                    }
                }

                if (drops > 1) {
                    valid = false;
                    break;
                }

                int block_min = (drops == 0) ? nums[start] : nums[start + (drop_idx + 1) % k];
                int block_max = (drops == 0) ? nums[start] : nums[start + drop_idx];

                if (b > 0 && block_min < prev_max) {
                    valid = false;
                    break;
                }

                prev_max = block_max;
            }

            if (valid) {
                sum_k += k;
            }
        }

        return sum_k;
    }
};