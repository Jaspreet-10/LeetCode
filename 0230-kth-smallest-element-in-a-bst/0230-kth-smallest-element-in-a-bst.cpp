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
    int helper(TreeNode* root, int k, int &ans, int &cnt){
        if(!root) return -1;
        if(helper(root->left, k, ans, cnt)!=-1) return ans;
        ++cnt;
        if(cnt == k){ 
            ans = root->val;
            return root->val;
        }
        if(helper(root->right, k, ans, cnt)!=-1) return ans;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0,cnt = 0;
        helper(root,k,ans,cnt);
        return ans;
    }
};