class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int rows = grid.size();
      int cols = grid[0].size();
      int islands = 0;

      const int dr[4] = {-1, 1, 0, 0};
      const int dc[4] = {0, 0, -1, 1};

      queue<pair<int, int>> q;

      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '1') {
                ++islands;
                grid[r][c] = '0';
                q.push({r, c});

                while (!q.empty()) {
                    auto [currR, currC] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; ++d) {
                        int nr = currR + dr[d];
                        int nc = currC + dc[d];

                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
      }  

      return islands;
    }
};