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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode*head=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(head->val);
            if(head->left) todo.push({head->left,{x-1,y+1}});
            if(head->right)todo.push({head->right,{x+1,y+1}});
        }
        vector<vector<int>>res;
        for(auto it:nodes){
            vector<int>ans;
            for(auto z:it.second){
                ans.insert(ans.end(),z.second.begin(),z.second.end());
            }
            res.push_back(ans);
        }
        return res;
    }
};