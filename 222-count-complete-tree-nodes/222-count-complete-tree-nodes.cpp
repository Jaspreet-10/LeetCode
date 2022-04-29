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
    int findLeftHeight(TreeNode* root){
        if(!root)
            return 0;
        int height = findLeftHeight(root->left);
        return height+1;
    }
    int findRightHeight(TreeNode* root){
        if(!root)
            return 0;
        int height = findRightHeight(root->right);
        return height+1;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh){
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};