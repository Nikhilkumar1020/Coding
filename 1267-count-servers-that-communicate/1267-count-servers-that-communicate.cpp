class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        int communicable_servers = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1)) {
                    communicable_servers++;
                }
            }
        }

        return communicable_servers;
    }
};