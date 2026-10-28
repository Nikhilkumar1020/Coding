class Solution {
    public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> reachable(m, vector<bitset<1024>>(n));
        reachable[0][0].set(grid[0][0]);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                int val = grid[i][j];
                bitset<1024> current;

                if (i > 0) {
                    for (int x = 0; x < 1024; ++x) {
                        if (reachable[i - 1][j].test(x)) {
                            current.set(x ^ val);
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; ++x) {
                        if (reachable[i][j - 1].test(x)) {
                            current.set(x ^ val);
                        }
                    }
                }

                reachable[i][j] = current;
            }
        }

        for (int x = 0; x < 1024; ++x) {
            if (reachable[m - 1][n - 1].test(x)) {
                return x;
            }
        }

        return -1;
    }
};