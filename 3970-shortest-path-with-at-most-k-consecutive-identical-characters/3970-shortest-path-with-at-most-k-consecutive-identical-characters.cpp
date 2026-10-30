class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if (n == 1) return 0;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> min_consec(n, 1e9);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, c] = pq.top();
            pq.pop();

            if (c >= min_consec[u]) {
                continue;
            }
            min_consec[u] = c;

            if (u == n - 1) {
                return cost;
            }

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                int next_c = (labels[u] == labels[v]) ? c + 1 : 1;

                if (next_c <= k) {
                    pq.push({cost + w, v, next_c});
                }
            }
        }

        return -1;
    }
};