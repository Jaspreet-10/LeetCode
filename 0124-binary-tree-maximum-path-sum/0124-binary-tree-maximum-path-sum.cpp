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
    int maximumPathSum(TreeNode* root){
        if(!root)
            return 0;
        int leftSum = max(0,maximumPathSum(root->left));
        int rightSum = max(0,maximumPathSum(root->right));
        if(leftSum+rightSum+root->val>maxi)
            maxi = leftSum+rightSum+root->val;
        return root->val+max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        maximumPathSum(root);
        return maxi;
    }
};

// Test case: 15,10,20, null, null,-30-15. will never give the right answer
//  if I will not apply that logic in the max condition.
//   Because taking negative values will never give me the right answer.