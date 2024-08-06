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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size = q.size();
            for(int i = size-1;i>=0;--i){
                TreeNode* head = q.front();
                temp.push_back(head->val);
                 q.pop();
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};