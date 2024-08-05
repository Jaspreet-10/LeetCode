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
    int findMaxDepth(TreeNode* root){
        if(!root) return 0;
        int lh = findMaxDepth(root->left);
        int rh = findMaxDepth(root->right);
        return max(lh, rh)+1;
    }
    int maxDepth(TreeNode* root) {
        return findMaxDepth(root);
    }
};