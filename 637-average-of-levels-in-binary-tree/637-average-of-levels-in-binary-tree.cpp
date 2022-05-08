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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double count = size;
            double totalSum = 0;
            for(int i = size-1;i>=0;--i){
                TreeNode* head = q.front();
                totalSum+=head->val;
                q.pop();
                if(head->left)
                    q.push(head->left);
                 if(head->right)
                    q.push(head->right);
            }
            ans.push_back(totalSum/count);
        }
        return ans;
    }
};