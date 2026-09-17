class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
      int n = arr.size();
      const int INF = 1e9;
      vector<int> minLens(n, INF);

      int ans = INF;
      int currentSum = 0;
      int left = 0;

      for (int right = 0; right < n; ++right) {
        currentSum += arr[right];

        while (currentSum > target && left <= right) {
            currentSum -= arr[left];
            ++left;
        }

        if (currentSum == target) {
            int currentLen = right - left + 1;

            if (left > 0 && minLens[left - 1] < INF) {
                ans = min(ans, currentLen + minLens[left - 1]);
            }

            int prevMin = (right > 0) ? minLens[right - 1] : INF;
            minLens[right] = min(prevMin, currentLen);
        } else {
            minLens[right] = (right > 0) ? minLens[right - 1] : INF;
        }
      }  

      return (ans >= INF) ? -1 : ans;
    }
};