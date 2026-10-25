class Solution {
    void dfs(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0) {
            return;
        }

        grid[r][c] = 1;

        dfs(r + 1, c, m, n, grid);
        dfs(r - 1, c, m, n, grid);
        dfs(r, c + 1, m, n, grid);
        dfs(r, c - 1, m, n, grid);
    }

    public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) dfs(i, 0, m, n, grid);
            if (grid[i][n - 1] == 0) dfs(i, n - 1, m, n, grid);
        }

        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 0) dfs(0, j, m, n, grid);
            if (grid[m - 1][j] == 0) dfs(m - 1, j, m, n, grid);
        }

        int closed_islands = 0;

        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    closed_islands++;
                    dfs(i, j, m, n, grid);
                }
            }
        }

        return closed_islands;
    }
};