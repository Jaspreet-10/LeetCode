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
    int maxi = INT_MIN;
    int diameter(TreeNode* root){
        if(!root)
            return 0;
        int lh = diameter(root->left);
        int rh = diameter(root->right);
        if(lh+rh>maxi)
            maxi = lh+rh;
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root){
        if(!root)
            return 0;
        diameter(root);
        return maxi;
    }
};