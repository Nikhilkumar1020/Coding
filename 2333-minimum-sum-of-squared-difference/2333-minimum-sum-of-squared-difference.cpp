class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int max_diff = 0;

        for (int i = 0; i < n; ++i) {
            max_diff = max(max_diff, abs(nums1[i] - nums2[i]));
        }

        vector<int> count(max_diff + 1, 0);
        for (int i = 0; i < n; ++i) {
            count[abs(nums1[i] - nums2[i])]++;
        }

        long long k = (long long)k1 + k2;

        for (int d = max_diff; d > 0; --d) {
            if (count[d] == 0) continue;

            if (k >= count[d]) {
                k -= count[d];
                count[d - 1] += count[d];
                count[d] = 0;
            } else {
                count[d - 1] += k;
                count[d] -= k;
                k = 0;
                break;
            }
        }

        long long ans = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (count[d] > 0) {
                ans += (long long)count[d] * d * d;
            }
        }

        return ans;
    }
};