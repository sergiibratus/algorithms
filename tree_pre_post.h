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
    TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        return construct(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
private:
    TreeNode* construct(const vector<int>& pre, int pre_start, int pre_finish, const vector<int>& post, int post_start, int post_finish) {
        if (pre_start > pre_finish)
            return NULL;
        
        if (pre_start == pre_finish)
            return new TreeNode(pre[pre_start]);
        
        TreeNode* node = new TreeNode(pre[pre_start]);
        
        int i = post_start;
        for (; i < post_finish; i++) {
            if (post[i] == pre[pre_start + 1]) {
                break;
            }
        }
        
        node->left = construct(pre, pre_start + 1, pre_start + 1 + (i - post_start), post, post_start, i);
        node->right = construct(pre, pre_start + 1 + (i - post_start) + 1, pre_finish, post, i + 1, post_finish - 1);
        
        return node;
    }
};