/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        m_result = INT_MIN; // clear the result from the previous call
        solve(root);
        return m_result;
    }
private:
    int solve(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int lheight = solve(node->left);
        int rheight = solve(node->right);
        int maxheight = max(node->val, node->val + max(lheight, rheight));

        m_result = max(m_result, maxheight);
        m_result = max(m_result, lheight + rheight + node->val);
        return maxheight;
    }

    int m_result;
};

