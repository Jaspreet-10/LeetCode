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
        if(!root) return NULL;
        if(!root->left && val<root->val && !flag){
            flag = true;
            return root->left = new TreeNode(val);
        }
        if(!root->right && val>root->val && !flag){
            flag = true;
            return root->right = new TreeNode(val);

        }
        if(root->val<val)
        insertIntoBSTHelper(root->right,val);
        else
        insertIntoBSTHelper(root->left,val);
         return NULL;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        insertIntoBSTHelper(root,val);
        return root;
    }
};