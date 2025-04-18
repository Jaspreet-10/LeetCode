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
    int count = 0;
    int countGoodNodes(TreeNode* root, int maxi){
        if(!root) return count;
        if(root->val>=maxi){
            ++count;
        }
        countGoodNodes(root->left, max(root->val, maxi));
        countGoodNodes(root->right, max(root->val, maxi));
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxi = INT_MIN;
        return countGoodNodes(root, maxi);
    }
};