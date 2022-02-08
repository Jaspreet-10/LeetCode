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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>>res;
    if(root==NULL) return res;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>v;
        int size=q.size();
        for(int i=0;i<size;++i){
            TreeNode*head=q.front();
            q.pop();
            if(head->right!=NULL) q.push(head->right);
            if(head->left!=NULL) q.push(head->left);
            v.insert(v.begin(),head->val);
        }
        res.insert(res.begin(),v);
    }
    return res;
    }
};