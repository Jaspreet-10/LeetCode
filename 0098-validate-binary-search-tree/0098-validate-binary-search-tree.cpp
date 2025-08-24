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
    bool helper(TreeNode* root, long long min, long long max){
        if(!root) return true;
        if(root->val>min and root->val<max){
            return helper(root->left, min, root->val) and helper(root->right, root->val, max);
        }else return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long min = LLONG_MIN, max = LLONG_MAX;
        if(helper(root, min, max)) return true;
        return false;
    }
};