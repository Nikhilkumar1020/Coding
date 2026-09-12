class Solution {
struct Interval {
    int l;
    int r;
    int weight;
    int id;
};
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
      int n = intervals.size();
      vector<Interval> arr(n);

      for (int i = 0; i < n; ++i) {
        arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
      }  

      sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
        if (a.l != b.l) {
            return a.l < b.l;
        }
        return a.r < b.r;
      });

      vector<int> starts(n);
      for (int i = 0; i < n; ++i) {
        starts[i] = arr[i].l;
      }

      vector<int> nxt(n);
      for (int i = 0; i < n; ++i) {
        nxt[i] = lower_bound(starts.begin(), starts.end(), arr[i].r + 1) - starts.begin();
      }

      vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0, {}}));

      for (int i = n - 1; i >= 0; --i) {
        for (int k = 1; k <= 4; ++k) {
            auto best = dp[i + 1][k];

            long long takeWeight = arr[i].weight + dp[nxt[i]][k - 1].first;
            vector<int> takeIndices;
            takeIndices.reserve(k);
            takeIndices.push_back(arr[i].id);

            for (int id : dp[nxt[i]][k - 1].second) {
                takeIndices.push_back(id);
            }

            sort(takeIndices.begin(), takeIndices.end());

            if (takeWeight > best.first) {
                best = {takeWeight, move(takeIndices)};
            } else if (takeWeight == best.first) {
                if (best.second.empty() || takeIndices < best.second) {
                    best = {takeWeight, move(takeIndices)};
                }
            }

            dp[i][k] = move(best);
        }
      }

      return dp[0][4].second;
    }
};