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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(!p and q) return false;
        if(!q and p) return false;
        if(p and q){
          if(p->val==q->val){
              if(isSameTree(p->left,q->left)==false) return false;
          }else return false;
        }else return false;
        if(p and q){
          if(p->val==q->val){
              if(isSameTree(p->right,q->right)==false) return false;
          }else return false;
        }else return false;
        return true;
    }
};