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
    bool value;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true;
        if(!p and q) return false;
        if(p and !q) return false;
        if(p->val!=q->val) return false;
        value=isSameTree(p->left,q->left);
        if(value== false) return false;
        value=isSameTree(p->right,q->right);
        if(value==false) return false;
        return value;
    }
};