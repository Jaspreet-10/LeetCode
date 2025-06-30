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
    int findGoodNodes(TreeNode* root, int maxi){
        if(!root) return count;
        if(maxi<=root->val) ++count;
        findGoodNodes(root->left, max(root->val, maxi));
        findGoodNodes(root->right, max(root->val, maxi));
        return count;
    }
    int goodNodes(TreeNode* root) {
        findGoodNodes(root, root->val);
        return count;
    }
};