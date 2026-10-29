class Solution {
    long long dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] <= 0) {
            return 0;
        }

        long long sum = grid[r][c];
        grid[r][c] = 0;

        sum += dfs(r + 1, c, m, n, grid);
        sum += dfs(r - 1, c, m, n, grid);
        sum += dfs(r, c + 1, m, n, grid);
        sum += dfs(r, c - 1, m, n, grid);

        return sum;
    }

    public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long total_val = dfs(i, j, m, n, grid);
                    if (total_val % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};