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
    bool flag = true;
    bool validBST(TreeNode* root,long long mini,long long maxi){
        if(!root)
            return true;
            if(root->val>mini && root->val<maxi)
            validBST(root->left,mini,root->val);
            else{
                flag = false;
                return false;
            }
            if(root->val>mini && root->val<maxi)
            validBST(root->right,root->val,maxi);
            else{
                flag = false;
                return false;
            }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long mini = LLONG_MIN, maxi = LLONG_MAX;
        validBST(root,mini,maxi);
        return flag;
    }
};