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
    bool balancedTree = true;
    int findMaxDepth(TreeNode* root){
        if(!root) return 0;
        int leftHeight = findMaxDepth(root->left);
        if(!balancedTree) return -1;
        int rightHeight = findMaxDepth(root->right);
        if(!balancedTree) return -1;
        if(abs(leftHeight - rightHeight)>1){
            balancedTree = false;
            return -1;
        }
        return max(leftHeight, rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(findMaxDepth(root) == -1) return false;
        return true;
    }
};