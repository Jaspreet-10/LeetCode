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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxi = 0;
        while(!q.empty()){
            int cur_min = q.front().second;
            int size = q.size();
            int left = 0, right = 0;
            for(int i = 0 ; i < size ; ++i){
                TreeNode* head = q.front().first;;
                int j = q.front().second-cur_min;
                if(i == 0)
                    left = j;
                if(i == size-1)
                    right = j;
                q.pop();
                if(head->left){
                    q.push({head->left,(long long)2*j+1});
                }
                 if(head->right){
                    q.push({head->right,(long long)2*j+2});
                }
            }
            maxi = max(maxi,(right-left+1));
        }
        return maxi;
    }
};