class Solution {
public:
    long long countCommas(long long n) {
     if (n < 1000) {
        return 0;
     }

     long long total = 0;
     long long base = 1000;

     while (base <= n) {
        total += (n - base + 1);

        if (base > LLONG_MAX / 1000) {
            break;
        }
        base *= 1000;
     }

     return total;
    }
};