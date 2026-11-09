class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        vector<int> counts(k, 0);

        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i];
            int duration = load[i];

            while (!busy.empty() && busy.top().first <= start) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) {
                continue;
            }

            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }

            int server_idx = *it;
            available.erase(it);
            busy.push({start + duration, server_idx});
            counts[server_idx]++;
        }

        int max_req = *max_element(counts.begin(), counts.end());
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_req) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};