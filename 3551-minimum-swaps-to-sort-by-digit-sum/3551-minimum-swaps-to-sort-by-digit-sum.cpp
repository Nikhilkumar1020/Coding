class Solution {
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || get<2>(arr[i]) == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(arr[j]);
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};