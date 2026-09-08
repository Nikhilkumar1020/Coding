class Solution {
public:
    int countCommas(int n) {
    if (n < 1000) {
        return 0;
    }

    int count = 0;
    long long base = 1000;

    while (base <= n) {
        count += (n - base + 1);
        base *= 1000;
    }

    return count;
    }
};