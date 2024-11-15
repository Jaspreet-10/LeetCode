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
    int findKthElement(TreeNode* root, int&k, int& value){
        if(!root) return value;
        findKthElement(root->left, k, value);
        --k;
        if(k == 0) return value = root->val;
        findKthElement(root->right, k, value);
        return value;
    }
    int kthSmallest(TreeNode* root, int k) {
        int value = 0;
        return findKthElement(root, k, value);
    }
};