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
    bool findSubRoot(TreeNode* root, TreeNode* subRoot){
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        if(root->val == subRoot->val){
            if(!findSubRoot(root->left, subRoot->left)) return false;
            if(!findSubRoot(root->right, subRoot->right)) return false;
        }else return false;
        return true;
    }
    bool dfs(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;
        if(root->val == subRoot->val){
            if(findSubRoot(root, subRoot)) return true;
        }
        if(dfs(root->left, subRoot) || dfs(root->right,subRoot)) return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root or !subRoot) return false;
        return dfs(root, subRoot);
    }
};