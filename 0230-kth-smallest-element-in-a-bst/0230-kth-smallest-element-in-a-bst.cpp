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
    int element = 0;
    int findElement(TreeNode* root,int k , int &cnt){
        if(!root)
            return 0;
        findElement(root->left,k,cnt);
        ++cnt;
        if(cnt == k){
            element =  root->val;
            return 0;
        }
        findElement(root->right,k,cnt);
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        findElement(root,k,cnt);
        return element;
    }
};