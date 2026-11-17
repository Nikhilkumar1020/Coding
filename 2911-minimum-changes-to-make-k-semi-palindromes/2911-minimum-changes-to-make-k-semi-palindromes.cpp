class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();

        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (size_t d_idx = 0; d_idx < divisors[len].size(); ++d_idx) {
                    int d = divisors[len][d_idx];
                    int current_cost = 0;
                    for (int c = 0; c < d; ++c) {
                        int left = i + c;
                        int right = i + c + len - d;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                current_cost++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    if (current_cost < cost[i][j]) {
                        cost[i][j] = current_cost;
                    }
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;

        for (int p = 1; p <= k; ++p) {
            for (int i = p * 2; i <= n; ++i) {
                for (int j = (p - 1) * 2; j <= i - 2; ++j) {
                    if (dp[j][p - 1] != 1e9 && cost[j][i - 1] != 1e9) {
                        if (dp[j][p - 1] + cost[j][i - 1] < dp[i][p]) {
                            dp[i][p] = dp[j][p - 1] + cost[j][i - 1];
                        }
                    }
                }
            }
        }

        return dp[n][k];
    }
};