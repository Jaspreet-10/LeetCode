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
    int maxDepth(TreeNode* node) {
    if(node==NULL) return 0;
     queue<TreeNode*>q;
        q.push(node);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* head=q.front();
                q.pop();
                if(head->left!=NULL) q.push(head->left);
                if(head->right!=NULL)q.push(head->right);
            }
            count++;
        }
        return count;   
    }
};