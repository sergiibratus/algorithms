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
    void recoverTree(TreeNode* root) {
        
        preorder(root);

        if (firstBad == nullptr)
            return;
        if (secondBad == nullptr) {
            swap(firstBad->val, firstBadPre->val);
        } else {
            swap(firstBadPre->val, secondBad->val);
        }
    }
private:
    void preorder(TreeNode* root) {
        if (root == nullptr)
            return;

        preorder(root->left);
        if (pre != nullptr) {
            if (pre->val > root->val) {
                if (firstBad == nullptr) {
                    firstBad = root;
                    firstBadPre = pre;
                }
                else {
                    secondBad = root;
                    secondBadPre = pre;
                }
            }
        }

        pre = root;
        preorder(root->right);
    }
    
    TreeNode* firstBad = nullptr;
    TreeNode* firstBadPre = nullptr;
    TreeNode* secondBad = nullptr;
    TreeNode* secondBadPre = nullptr;
    
    TreeNode* pre = nullptr;
};

