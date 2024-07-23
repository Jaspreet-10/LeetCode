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
    bool flag = false;
    TreeNode* insertIntoBSTHelper(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        if(root->val<val)
        root->right = insertIntoBSTHelper(root->right,val);
        else
        root->left = insertIntoBSTHelper(root->left,val);
         return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertIntoBSTHelper(root,val);
    }
};