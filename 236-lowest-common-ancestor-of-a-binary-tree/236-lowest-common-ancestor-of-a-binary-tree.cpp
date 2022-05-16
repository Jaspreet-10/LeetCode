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
        if(root==p or root==q)
            return root;
        TreeNode* leftRoot = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightRoot = lowestCommonAncestor(root->right,p,q);
        if(leftRoot==NULL)
            return rightRoot;
         if(rightRoot==NULL)
            return leftRoot;
        return root;
    }
};