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
    int pathSum(TreeNode*root,int S,int &sum,int& flag){
        if(!root) 
            return 0;
        sum+=root->val;
        pathSum(root->left,S,sum,flag);
        if(!root->left and !root->right and sum==S){
            flag=sum;
            return sum;
        }
        pathSum(root->right,S,sum,flag);
        sum-=root->val;
        return sum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum=0,flag=1001;
        pathSum(root,targetSum,sum,flag);
        if(flag==targetSum)
        return 1;
        return 0;
    }
};