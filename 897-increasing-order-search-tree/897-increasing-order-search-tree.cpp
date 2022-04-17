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
    TreeNode *head = new TreeNode(0);
    TreeNode* dummy = head;
    TreeNode* sortedOrder(TreeNode* root){
        if(root==NULL)
            return NULL;
        sortedOrder(root->left);
        dummy->right = new TreeNode(root->val);
        dummy->left = NULL;
        dummy = dummy->right;
        sortedOrder(root->right);
        return dummy;
    }
    TreeNode* increasingBST(TreeNode* root) {
        sortedOrder(root);
        return head->right;
    }
};