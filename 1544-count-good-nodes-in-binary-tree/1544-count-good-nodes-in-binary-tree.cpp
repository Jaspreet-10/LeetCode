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
    int countGoodNodes(TreeNode* root, int maxValue, int & count){
        if(!root) return 0;
        if(root->val >= maxValue) ++count;
        maxValue = max(maxValue, root->val);
        countGoodNodes(root->left, maxValue, count);
        countGoodNodes(root->right, maxValue, count);
        return count;
    }
    int goodNodes(TreeNode* root) {
        int maxValue = INT_MIN, count = 0;
        return countGoodNodes(root, maxValue, count);
    }
};