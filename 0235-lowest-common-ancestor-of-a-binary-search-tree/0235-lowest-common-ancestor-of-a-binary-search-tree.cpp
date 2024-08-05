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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root == p or root == q)
            return root;
        TreeNode* right = lowestCommonAncestor(root->left,p,q);
        TreeNode* left = lowestCommonAncestor(root->right,p,q);
        if(!right && !left)
            return NULL;
        if(!right)
            return left;
        if(!left)
            return right;
        return root;
    }
};