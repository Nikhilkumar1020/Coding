class Solution {
    void dfs(int u, const vector<vector<int>>& adj, const vector<int>& parent,
    const string& s, vector<int>& last_seen, vector<int>& ans) {
        int c = s[u] - 'a';
        int prev = last_seen[c];
        int new_parent = (prev != -1) ? prev : parent[u];

        last_seen[c] = u;
        for (size_t i = 0; i < adj[u].size(); ++i) {
            dfs(adj[u][i], adj, parent, s, last_seen, ans);
        }
        last_seen[c] = prev;

        if (new_parent != -1) {
            ans[new_parent] += ans[u];
        }
    };

    public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last_seen(26, -1);
        vector<int> ans(n, 1);
        dfs(0, adj, parent, s, last_seen, ans);

        return ans;
    }
};