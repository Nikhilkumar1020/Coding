/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
    int matchCount = 0;

    auto dfs = [&](auto& self, TreeNode* node) -> pair<int, int> {
        if (!node) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = self(self, node->left);
        auto [rightSum, rightCount] = self(self, node->right);

        int currentSum = node->val + leftSum + rightSum;
        int currentCount = 1 + leftCount + rightCount;

        if (node->val == currentSum / currentCount) {
            ++matchCount;
        }

        return {currentSum, currentCount};
    };

      dfs(dfs, root);
      return matchCount;
    }
};