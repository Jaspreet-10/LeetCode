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
    bool checkPalindrome(unordered_map<int,int>&m){
        int countOdd = 0;
        for(auto it:m){
            if(it.second%2!=0)++countOdd;
            if(countOdd>1) return false;
        }
        return true;
    }
    int dfs(TreeNode* root, unordered_map<int,int>&m, int&cnt){
        if(!root) return cnt;
         m[root->val]++;
        if(!root->left && !root->right){
            if(checkPalindrome(m)) ++cnt;
        }
        dfs(root->left,m,cnt);
        dfs(root->right,m,cnt);
        m[root->val]--;
        return cnt;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        unordered_map<int,int>m;
        int cnt = 0;
        return dfs(root,m,cnt);
    }
};