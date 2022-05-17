/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans=NULL;
    TreeNode* findNode(TreeNode* cloned, TreeNode* target){
        if(!cloned)
            return NULL;
        if(cloned->val==target->val){
            ans = cloned;
            return cloned;
        }
        findNode(cloned->left,target);
        if(ans!=NULL)
            return ans;
        findNode(cloned->right,target);
         if(ans!=NULL)
            return ans;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        findNode(cloned,target);
        return ans;
    }
};