class Solution {
    struct Node {
        int remain[5] = {0};
        int prod = 1;
    };

    int n;
    int k;
    vector<Node> tree;

    void build(const vector<int>& nums, int cur, int left, int right) {
        if (left == right) {
            tree[cur].remain[nums[left]] = 1;
            tree[cur].prod = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build(nums, 2 * cur + 1, left, mid);
        build(nums, 2 * cur + 2, mid + 1, right);
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }

    void update(int treeIndex, int lo, int hi, int i, int val) {
        if (lo == hi) {
            for (int j = 0; j < k; ++j) {
                tree[treeIndex].remain[j] = 0;
            }
            tree[treeIndex].remain[val] = 1;
            tree[treeIndex].prod = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if (i <= mid) {
            update(2 * treeIndex + 1, lo, mid, i, val);
        } else {
            update(2 * treeIndex + 2, mid + 1, hi, i, val);
        }
        tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }

    Node query(int treeIndex, int lo, int hi, int i, int j) const {
        if (i <= lo && hi <= j) {
            return tree[treeIndex];
        }
        if (j < lo || hi < i) {
            return Node();
        }
        int mid = (lo + hi) / 2;
        return merge(query(2 * treeIndex + 1, lo, mid, i, j), query(2 * treeIndex + 2, mid + 1, hi, i, j));
    }

    Node merge(const Node& left, const Node& right) const {
        Node node;
        node.prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; ++i) {
            node.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k; ++i) {
            node.remain[(i * left.prod) % k] += right.remain[i];
        }
        return node;
    }

    public:
    vector<int> resultArray(vector<int>& nums, int k_val, vector<vector<int>>& queries) {
        k = k_val;
        for (int& num : nums) {
            num %= k;
        }
        for (auto& q : queries) {
            q[1] %= k;
        }

        n = nums.size();
        tree.assign(4 * n, Node());
        build(nums, 0, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(0, 0, n - 1, index, value);
            ans.push_back(query(0, 0, n - 1, start, n - 1).remain[x]);
        }

        return ans;
    }
};