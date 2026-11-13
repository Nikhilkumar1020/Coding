class Solution {
private:
long long getCost(long long k, int cost1, int cost2, int costBoth, int need1, int need2) {
        long long rem1 = max(0LL, (long long)need1 - k);
        long long rem2 = max(0LL, (long long)need2 - k);
        return k * costBoth + rem1 * cost1 + rem2 * cost2;
    }

    public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long costAtZero = getCost(0, cost1, cost2, costBoth, need1, need2);
        long long costAtNeed1 = getCost(need1, cost1, cost2, costBoth, need1, need2);
        long long costAtNeed2 = getCost(need2, cost1, cost2, costBoth, need1, need2);

        return min({costAtZero, costAtNeed1, costAtNeed2});
    }
};