class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int minPrice = INT_MAX;
        int maxFactor = 0;

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

        for (int i = 1; i <= maxFactor; ++i) {
            if (freq[i] > 0) {
                for (int multiple = 2 * i; multiple <= maxFactor; multiple += i) {
                    freq[i] += freq[multiple];
                }
            }
        }

        map<int, long long> boostedByPrice;
        long long limit = 2LL * minPrice;
        for (size_t i = 0; i < items.size(); ++i) {
            int factor = items[i][0];
            int price = items[i][1];
            int gain = freq[factor] - 1;
            if (gain > 0 && price < limit) {
                boostedByPrice[price] += gain;
            }
        }

        long long totalItems = 0;
        long long remBudget = budget;

        for (map<int, long long>::const_iterator it = boostedByPrice.begin(); it != boostedByPrice.end(); ++it) {
            int price = it->first;
            long long count = it->second;
            long long canBuy = min(count, remBudget / price);

            totalItems += 2 * canBuy;
            remBudget -= canBuy * price;

            if (remBudget == 0) {
                break;
            }
        }

        totalItems += remBudget / minPrice;
        return static_cast<int>(totalItems);
    }
};