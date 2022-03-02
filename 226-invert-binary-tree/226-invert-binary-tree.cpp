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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* res=root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*head=q.front();
            q.pop();
            if(head->left and head->right){
                TreeNode*temp=head->left;
                head->left=head->right;
                head->right=temp;
                q.push(head->left);
                q.push(head->right);
            }
            else if(!head->left and head->right){
                head->left=head->right;
                head->right=NULL;
                q.push(head->left);
            }
            else if(!head->right and head->left){
                head->right=head->left;
                head->left=NULL;
                q.push(head->right);
            } 
        }
        return res;
    }
};