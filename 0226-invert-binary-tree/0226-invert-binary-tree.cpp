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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        if(root->left and root->right){
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        else if(root->left){
            TreeNode* temp = NULL;
            root->right = root->left;
            root->left = NULL;
        }
        else if(root->right){
            TreeNode* temp = NULL;
            root->left = root->right;
            root->right = NULL;
        }
            if(root->left)
            invertTree(root->left);
            if(root->right)
            invertTree(root->right);
        return root;
    }
};