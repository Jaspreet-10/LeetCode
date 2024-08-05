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
    void invertBT(TreeNode* root){
        if(!root) return;
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
        invertBT(root->left);
        invertBT(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        invertBT(root);
        return root;
    }
};