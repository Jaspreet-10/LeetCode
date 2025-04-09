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
    bool bbt = true;
    int findMaxDepth(TreeNode* root){
        if(!root) return 0;
        int lh = findMaxDepth(root->left);
        if(bbt == false) return false;
        int rh = findMaxDepth(root->right);
        if(bbt == false) return false;
        if(abs(lh-rh)>1){
            bbt = false;
            return false;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
         findMaxDepth(root);
         return bbt;
    }
};