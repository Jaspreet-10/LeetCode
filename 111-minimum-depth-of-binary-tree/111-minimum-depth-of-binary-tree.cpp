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
    int minDepth(TreeNode* node) {
        if(node==NULL) return 0;
     queue<TreeNode*>q;
        q.push(node);
        int count=0,leafR=0,leafL=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                leafR=0,leafL=0;
                TreeNode* head=q.front();
                q.pop();
                if(head->left!=NULL){
                    leafL=-1;
                    q.push(head->left);
                }
                if(head->right!=NULL){
                    leafR=-1;
                    q.push(head->right);
                }
                if(leafL!=-1 and leafR!=-1)
                    return count+1;
            }
            count++;
        }
        return count;
    }
};