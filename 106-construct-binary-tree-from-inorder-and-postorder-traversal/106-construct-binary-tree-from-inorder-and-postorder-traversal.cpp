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
    TreeNode* treeConstruct(vector<int>post,int postStart,int postEnd,vector<int>in,int inStart,
    int inEnd,unordered_map<int,int>&m){
        if(postStart>postEnd || inStart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(post[postEnd]);
        int inRoot = m[post[postEnd]];
        int numsLeft = inRoot-inStart;
        root->left = treeConstruct(post,postStart,postStart+numsLeft-1,in,inStart,
                                    inRoot-1,m);
        root->right = treeConstruct(post,postStart+numsLeft,postEnd-1,in,inRoot+1,
                                    inEnd,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int>m;
        int n = post.size();
        for(int i = 0 ; i < n ; ++i){
            m[in[i]]=i;
        }
        TreeNode* root = treeConstruct(post,0,n-1,in,0,n-1,m);
        return root;
    }
};