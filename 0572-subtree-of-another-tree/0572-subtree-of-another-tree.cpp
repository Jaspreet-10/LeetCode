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
    bool helper(TreeNode* root, TreeNode* subRoot){
         if(!root && !subRoot) return true;
         if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            return helper(root->left, subRoot->left) && 
                   helper(root->right, subRoot->right);
        }else return false;
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            if(helper(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};