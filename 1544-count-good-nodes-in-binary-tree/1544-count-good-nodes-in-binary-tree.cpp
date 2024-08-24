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
    int findGoodNodes(TreeNode* root, int &cnt, int maxi){
        if(!root) return 0;
        if(root->val >= maxi){
            maxi = root->val;
            ++cnt;
        }
        findGoodNodes(root->left, cnt, maxi);
        findGoodNodes(root->right, cnt, maxi);
        return cnt;
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0, maxi = INT_MIN;
        if(!root) return 0;
        return findGoodNodes(root, cnt, maxi);
    }
};