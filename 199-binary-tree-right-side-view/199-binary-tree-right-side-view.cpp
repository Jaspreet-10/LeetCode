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
    vector<int> rightSideView(TreeNode* root) {
   vector<int>v;
   if(root==NULL) return v;
   queue<TreeNode*>q;
   stack<int>st;
   q.push(root);
   while(!q.empty()){
       int size=q.size();
       for(int i=size-1;i>=0;--i){
           TreeNode*head=q.front();
           q.pop();
            st.push(head->val);
            if(head->left) q.push(head->left);
            if(head->right) q.push(head->right);
           }
           v.push_back(st.top());
       }
   return v;
    }
};