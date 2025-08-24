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
         if(!root) return {};
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size()-1;
            for(int i = size ; i>=0 ; --i){
                TreeNode* head = q.front();
                q.pop();
                if(i == 0)
                v.push_back(head->val);
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
            }
        }
        return v;
    }
};