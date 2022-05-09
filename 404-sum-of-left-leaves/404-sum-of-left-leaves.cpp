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
    int leftSum(TreeNode* root,bool tracker,int&sum){
        
        if(!root)
            return sum;
        
        if(root->left==NULL and root->right==NULL and tracker){
            sum+=root->val;
            return sum;
        }
        
        leftSum(root->left,true,sum);
        leftSum(root->right,false,sum);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        return leftSum(root,false,sum);
    }
};