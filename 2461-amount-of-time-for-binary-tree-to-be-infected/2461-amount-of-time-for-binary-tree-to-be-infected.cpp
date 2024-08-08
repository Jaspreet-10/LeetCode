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
    TreeNode* s = NULL;
    void HeadNodes(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&m, int start){
        if(!root) return;
        if(root->val == start) s = root;
        if(root->left){
            m[root->left] = root;
            HeadNodes(root->left,m, start);
        }
        if(root->right){
            m[root->right] = root;
            HeadNodes(root->right,m,start);
        }
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        unordered_map<TreeNode*,TreeNode*>m;
        HeadNodes(root,m,start);
        int cnt = 0;
        unordered_map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(s);
        vis[s] = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; ++i){
                TreeNode* head = q.front();
                q.pop();
                if(m.find(head)!=m.end() && vis[m[head]] == 0){
                    vis[m[head]] = 1;
                    q.push(m[head]);
                }
                if(head->left && vis[head->left] == 0){
                    vis[head->left] = 1;
                    q.push(head->left);
                }
                if(head->right && vis[head->right] == 0){
                    vis[head->right] = 1;
                    q.push(head->right);
                }
            }
            ++cnt;
        }
        return cnt-1;
    }
};