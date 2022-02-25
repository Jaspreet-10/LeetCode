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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            vector<int>v;
            int size=q.size();
            for(int i=size-1;i>=0;--i){
                TreeNode* head=q.front();
                q.pop();
                if(flag==0){
                    v.push_back(head->val);
                }
                else{
                    v.push_back(head->val);
                }
                if(head->left!=NULL)
                    q.push(head->left);
                if(head->right!=NULL)
                    q.push(head->right);
            }
            if(flag==0){
                res.push_back(v);
                flag=1;
            }else{
                reverse(v.begin(),v.end());
                res.push_back(v);
                flag=0;
            }
        }
        return res;
    }
};