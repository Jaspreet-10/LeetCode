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
    int maximumNode(TreeNode* root, int maxi, int& cnt){
        if(!root) return cnt;
        maxi = max(maxi, root->val);
        if(root->val>=maxi)++cnt;
        maximumNode(root->left, maxi, cnt);
        maximumNode(root->right, maxi, cnt);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        int maxi = root->val;
       return maximumNode(root, maxi, cnt);
    }
};