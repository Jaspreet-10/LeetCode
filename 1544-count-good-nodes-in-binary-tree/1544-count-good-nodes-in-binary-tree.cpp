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
    int cnt = 0;
    int findGoodNodes(TreeNode* root, int maxi){
        if(!root) return 0;
        if(root->val >= maxi) ++cnt;
        if(root->val > maxi) maxi = root->val;
        int lh = findGoodNodes(root->left, maxi);
        int rh = findGoodNodes(root->right, maxi);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxi = root->val;
        findGoodNodes(root,maxi);  
        return cnt; 
    }
};