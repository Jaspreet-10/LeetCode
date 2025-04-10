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
    int findMaximumPath(TreeNode* root, int &maxi){
        if(!root) return INT_MIN;
        int leftSum = max(0,findMaximumPath(root->left, maxi));
        int rightSum = max(0,findMaximumPath(root->right, maxi));
        if(leftSum+rightSum+root->val>=maxi){
            maxi = leftSum+rightSum+root->val;
        }
        return max(leftSum, rightSum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        findMaximumPath(root, maxi);
        return maxi;
    }
};