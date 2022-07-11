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
        vector<int>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* head;
            for(int i = q.size()-1;i>=0;--i){
                head = q.front();
                q.pop();
                if(i==0)
                    ans.push_back(head->val);
                if(head->left)
                    q.push(head->left);
                if(head->right)
                    q.push(head->right);
            }
        }
        return ans;
    }
};