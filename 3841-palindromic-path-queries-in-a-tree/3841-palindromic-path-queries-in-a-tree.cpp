class Solution {
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    int tree_size;

    void update(int idx, int val) {
        for (; idx <= tree_size; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum ^= bit[idx];
        }
        return sum;
    }

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        tin[u] = ++timer;
        up[u][0] = p;
        depth[u] = d;

        for (int i = 1; i < 20; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }

        tout[u] = timer;
    }

    int getLca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = 19; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = 19; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        tree_size = n;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(20, 0));
        bit.assign(n + 2, 0);

        dfs(0, 0, 0, adj);

        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            update(tin[i], mask);
            update(tout[i] + 1, mask);
        }

        vector<bool> ans;

        for (const string& q_str : queries) {
            stringstream ss(q_str);
            string type;
            ss >> type;

            if (type == "update" || type == "1") {
                int u;
                char c;
                ss >> u >> c;

                int old_mask = 1 << (s[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;

                update(tin[u], diff);
                update(tout[u] + 1, diff);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int lca = getLca(u, v);
                int u_mask = query(tin[u]);
                int v_mask = query(tin[v]);
                int lca_mask = query(tin[lca]);
                int lca_node_mask = 1 << (s[lca] - 'a');

                int path_mask = u_mask ^ v_mask ^ lca_node_mask;

                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};