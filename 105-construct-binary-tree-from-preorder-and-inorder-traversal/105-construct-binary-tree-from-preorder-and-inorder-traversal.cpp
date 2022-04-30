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
    TreeNode* treeConstruct(vector<int>pre,int preStart,int preEnd,vector<int>in,int inStart,
    int inEnd,unordered_map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        int inRoot = m[pre[preStart]];
        int numsLeft = inRoot-inStart;
        root->left = treeConstruct(pre,preStart+1,preStart+numsLeft,in,inStart,
                                    inRoot-1,m);
        root->right = treeConstruct(pre,preStart+numsLeft+1,preEnd,in,inRoot+1,
                                    inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int>m;
        int n = pre.size();
        for(int i = 0 ; i < n ; ++i){
            m[in[i]]=i;
        }
        TreeNode* root = treeConstruct(pre,0,n-1,in,0,n-1,m);
        return root;
    }
};