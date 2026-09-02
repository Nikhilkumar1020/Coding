class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int low = 1;
      int high = 0;
      for (int pile : piles) {
        high = max(high, pile);
      }  

      int ans = high;

      while (low <= high) {
        int mid = low + (high - low) / 2;
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + mid - 1LL) / mid;
        }

        if (hours <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
      }

      return ans;
    }
};