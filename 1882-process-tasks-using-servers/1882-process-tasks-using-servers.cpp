class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        using tuple3 = tuple<long long, int, int>;
        priority_queue<tuple3, vector<tuple3>, greater<tuple3>> unavailable;

        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }

        long long current_time = 0;

        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);

            if (available.empty()) {
                current_time = max(current_time, get<0>(unavailable.top()));
            }

            while (!unavailable.empty() && get<0>(unavailable.top()) <= current_time) {
                auto [t, w, idx] = unavailable.top();
                unavailable.pop();
                available.push({w, idx});
            }

            auto [w, idx] = available.top();
            available.pop();
            ans[j] = idx;
            unavailable.push({current_time + tasks[j], w, idx});
        }

        return ans;
    }
};