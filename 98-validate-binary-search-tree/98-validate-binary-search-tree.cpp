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
    void inorder(TreeNode* root,vector<int>&v1){
        if(!root)
            return;
        inorder(root->left,v1);
        v1.push_back(root->val);
        inorder(root->right,v1);
        return ;
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v1,v2;
        unordered_map<int,int>m1;
        inorder(root,v1);
        v2 = v1;
        sort(v2.begin(),v2.end());
        for(int i = 0 ; i < v2.size() ; ++i){
            if(v2[i]!=v1[i] || m1[v2[i]]>0)
                return false;
            m1[v2[i]]++;
        }
        return true;
    }
};