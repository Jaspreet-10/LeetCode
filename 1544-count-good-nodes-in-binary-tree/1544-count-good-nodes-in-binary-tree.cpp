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
    int checkGoodNodes(TreeNode* root, int maxi, int &count){
        if(!root) return count;
        if(maxi<=root->val)++count;
        checkGoodNodes(root->left, max(maxi, root->val), count);
        checkGoodNodes(root->right, max(maxi, root->val), count);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxi = root->val, count = 0;
        return checkGoodNodes(root, maxi, count);
    }
};