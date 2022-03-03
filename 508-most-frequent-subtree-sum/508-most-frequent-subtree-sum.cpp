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
        map<int,int>map;
        int dfs(TreeNode* node,int &ms){
        if(!node){return 0;}
        int sum = dfs(node->left,ms)+ dfs(node->right,ms)+node->val;
        map[sum]++;
        ms = max(ms,map[sum]);
        return sum;        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int ms = 0;
        dfs(root,ms);
        vector<int> ans;
        for(auto x:map){
            if(x.second == ms){
                ans.push_back(x.first);
            }
        }
        return ans;        
    }
};