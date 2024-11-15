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
    int findMaximumPathSum(TreeNode *root, int& maxi){
        if(!root) return 0;
        int leftSum = max(0, findMaximumPathSum(root->left, maxi));
        int rightSum = max(0, findMaximumPathSum(root->right, maxi));
        if(leftSum + rightSum + root->val > maxi)
            maxi = leftSum + rightSum + root->val;
        return max(leftSum, rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaximumPathSum(root, maxi);
        return maxi;
    }
};