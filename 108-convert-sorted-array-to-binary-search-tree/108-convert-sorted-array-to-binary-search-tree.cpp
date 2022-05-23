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
    TreeNode* convertBST(int low,int high,vector<int>&nums){
        if(low>high)
            return NULL;
        int mid = low+(high-low)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = convertBST(low,mid-1,nums);
        newNode->right = convertBST(mid+1,high,nums);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = convertBST(0,nums.size()-1,nums);
        return root;
    }
};