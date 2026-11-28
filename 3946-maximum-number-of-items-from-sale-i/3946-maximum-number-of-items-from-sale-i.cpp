class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i][0] > maxFactor) {
                maxFactor = items[i][0];
            }
            if (items[i][1] < minPrice) {
                minPrice = items[i][1];
            }
        }

        vector<int> freq(maxFactor + 1, 0);
        for (size_t i = 0; i < items.size(); ++i) {
            freq[items[i][0]]++;
        }

        vector<int> firstGain(maxFactor + 1, 0);
        for (int f = 1; f <= maxFactor; ++f) {
            if (freq[f] > 0) {
                for (int mult = f; mult <= maxFactor; mult += f) {
                    firstGain[f] += freq[mult];
                }
            }
        }

        vector<int> dp(budget + 1, 0);
        for (size_t i = 0; i < items.size(); ++i) {
            int price = items[i][1];
            int gain = firstGain[items[i][0]];
            for (int b = budget; b >= price; --b) {
                if (dp[b - price] + gain > dp[b]) {
                    dp[b] = dp[b - price] + gain;
                }
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int total = dp[b] + (budget - b) / minPrice;
            if (total > ans) {
                ans = total;
            }
        }

        return ans;
    }
};