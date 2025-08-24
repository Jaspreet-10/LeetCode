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
    int helper(TreeNode* root, int maxi, int&count){
        if(!root) return 0;
        if(root->val>=maxi) ++count;
        helper(root->left, max(maxi, root->val), count);
        helper(root->right, max(maxi, root->val), count);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        helper(root, root->val, count);
        return count;
    }
};