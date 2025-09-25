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
    int helper(TreeNode* root, int &maxi){
        if(!root) return 0;
        int lh = helper(root->left, maxi);
        int rh = helper(root->right, maxi);
        if(lh+rh+1>maxi) maxi = lh+rh+1;
        return 1+max(lh, rh);
    }
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        return helper(root, maxi);
    }
};