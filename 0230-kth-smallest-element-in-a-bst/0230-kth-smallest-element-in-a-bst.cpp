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
    int inorder(TreeNode* root, int k, int&cnt, int&ans){
        if(!root) return 0;
        inorder(root->left,k,cnt,ans);
         ++cnt;
        if(cnt == k){
            return ans = root->val;
        }
        inorder(root->right,k,cnt,ans);
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = 0;
        inorder(root,k,cnt,ans);
        return ans;
    }
};