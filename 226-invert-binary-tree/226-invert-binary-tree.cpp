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
    TreeNode* invertTree(TreeNode* node) {
        if(node==NULL) return node;
        TreeNode*temp=node->left;
        node->left=node->right;
        node->right=temp;
        if(node->left)
           invertTree(node->left);
        if(node->right)
            invertTree(node->right);
            return node;
    }
};