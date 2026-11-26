class Solution {
    private:
    bool hasUniqueSubarray(int len, int n,
    const vector<long long>& pref1, const vector<long long>& pow1,
    const vector<long long>& pref2, const vector<long long>& pow2,
    long long mod1, long long mod2) {
        unordered_map<unsigned long long, int> counts;
        counts.reserve(n - len + 1);

        for (int i = 0; i <= n - len; ++i) {
            long long h1 = (pref1[i + len] - (pref1[i] * pow1[len]) % mod1 + mod1) % mod1;
            long long h2 = (pref2[i + len] - (pref2[i] * pow2[len]) % mod2 + mod2) % mod2;
            unsigned long long key = (static_cast<unsigned long long>(h1) << 32) | static_cast<unsigned long long>(h2);
            counts[key]++;
        }

        for (const pair<const unsigned long long, int>& entry : counts) {
            if (entry.second == 1) {
                return true;
            }
        }

        return false;
    };

    public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long base1 = 100003;
        const long long mod1 = 1000000007;
        const long long base2 = 100019;
        const long long mod2 = 1000000009;

        vector<long long> pref1(n + 1, 0), pow1(n + 1, 1);
        vector<long long> pref2(n + 1, 0), pow2(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            pref1[i + 1] = (pref1[i] * base1 + nums[i]) % mod1;
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pref2[i + 1] = (pref2[i] * base2 + nums[i]) % mod2;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
        }

        int left = 1;
        int right = n;
        int ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasUniqueSubarray(mid, n, pref1, pow1, pref2, pow2, mod1, mod2)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};