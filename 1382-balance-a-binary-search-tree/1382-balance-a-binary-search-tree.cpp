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
    void inOrder(TreeNode* root,vector<int>&v){
        if(!root)
            return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
        return;
    }
    TreeNode* balancedTree(int low,int high,vector<int>&v){
        if(low>high)
            return NULL;
        int mid = (low+high)/2;
        TreeNode* newNode = new TreeNode(v[mid]);
        newNode->left = balancedTree(low,mid-1,v);
        newNode->right = balancedTree(mid+1,high,v);
        return newNode;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inOrder(root,v);
      return balancedTree(0,v.size()-1,v);
    }
};