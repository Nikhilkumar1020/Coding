class Solution {
    public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        int max_bal = (m + n - 1) / 2;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(max_bal + 1, false)));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        visited[0][0][1] = true;

        while (!q.empty()) {
        auto [r, c, bal] = q.front();
        q.pop();
        
        if (r == m - 1 && c == n - 1 && bal == 0) {
        return true;
    }

    int dirs[2][2] = {{0, 1}, {1, 0}};
    for (auto& dir : dirs) {
    int nr = r + dir[0];
    int nc = c + dir[1];
    
    if (nr < m && nc < n) {
    int nbal = bal + (grid[nr][nc] == '(' ? 1 : -1);
    if (nbal >= 0 && nbal <= max_bal && !visited[nr][nc][nbal]) {
        visited[nr][nc][nbal] = true;
        q.push({nr, nc, nbal});
                }
            }
        }
    }

    return false;
    }
};