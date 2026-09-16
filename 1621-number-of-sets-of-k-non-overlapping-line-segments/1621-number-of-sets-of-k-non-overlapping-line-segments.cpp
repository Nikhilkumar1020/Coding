class Solution {
    private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % 1000000007;
            }
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

    public:
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        if (R > N) {
            return 0;
        }

        const int MOD = 1e9 + 7;
        long long num = 1;
        long long den = 1;

        for (int i = 0; i < R; ++i) {
            num = (num * (N - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        return (num * modInverse(den)) % MOD;
    }
};