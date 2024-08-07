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
    TreeNode* ans = NULL;
    TreeNode* searchBSTHelper(TreeNode* root, int val){
        if(!root) return NULL;
        if(root->val == val){
            ans = root;
            return ans;
        }
        if(root->val > val){
            if(searchBSTHelper(root->left,val)!=NULL) return ans;
        }
        else{
            if(searchBSTHelper(root->right,val)!=NULL) return ans;
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchBSTHelper(root, val);
    }
};