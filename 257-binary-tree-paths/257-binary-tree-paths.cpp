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
    void inorder(vector<string>&res,TreeNode* root,vector<string>&v){
     if(root==NULL)
        return;
        res.push_back(to_string(root->val));
        inorder(res,root->left,v);
     if(!root->left and !root->right){
         string str="";
         int i=0;
         for(i=0;i<res.size()-1;++i){
             str+=res[i]+"->";
         }
            str+=res[i];
         v.push_back(str);
     }
        inorder(res,root->right,v);
        res.pop_back();
        return ;
 }
    vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>v;
    vector<string>res;
    inorder(res,root,v);
    return v;   
    }
};