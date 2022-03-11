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
        if(!root) return NULL;
        if(root==p) return root;
        if(root==q) return root;
        TreeNode* right = lowestCommonAncestor(root->left,p,q);
        TreeNode* left = lowestCommonAncestor(root->right,p,q);
        if(right==NULL) return left;
        else if(left==NULL) return right;
        else
            return root;
    }
};