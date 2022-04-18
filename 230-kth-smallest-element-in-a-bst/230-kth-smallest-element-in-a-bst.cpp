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
    priority_queue<int>pq;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        kthSmallest(root->left,k);
        pq.push(root->val);
        if(pq.size()>k)
            pq.pop();
        kthSmallest(root->right,k);
        return pq.top();
    }
};