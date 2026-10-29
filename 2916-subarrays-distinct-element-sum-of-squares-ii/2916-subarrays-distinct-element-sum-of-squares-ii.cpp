class Solution {
    const int MOD = 1e9 + 7;

    struct Node {
        long long sum1; 
        long long sum2; 
        long long lazy;
    };

    vector<Node> tree;

    void push_up(int node) {
        tree[node].sum1 = (tree[2 * node].sum1 + tree[2 * node + 1].sum1) % MOD;
        tree[node].sum2 = (tree[2 * node].sum2 + tree[2 * node + 1].sum2) % MOD;
    }

    void apply(int node, int start, int end, long long val) {
        long long len = end - start + 1;
        long long sum1 = tree[node].sum1;

        tree[node].sum2 = (tree[node].sum2 + 2 * val * sum1 % MOD + val * val % MOD * len % MOD) % MOD;
        tree[node].sum1 = (tree[node].sum1 + val * len % MOD) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push_down(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            int mid = start + (end - start) / 2;
            apply(2 * node, start, mid, tree[node].lazy);
            apply(2 * node + 1, mid + 1, end, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }
        push_down(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        push_up(node);
    }

    public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 1, {0, 0, 0});
        unordered_map<int, int> last_pos;

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int l = last_pos.count(nums[i]) ? last_pos[nums[i]] + 1 : 1;
            int r = i + 1; 

            update(1, 1, n, l, r, 1);

            ans = (ans + tree[1].sum2) % MOD;

            last_pos[nums[i]] = i + 1;
        }

        return ans;
    }
};