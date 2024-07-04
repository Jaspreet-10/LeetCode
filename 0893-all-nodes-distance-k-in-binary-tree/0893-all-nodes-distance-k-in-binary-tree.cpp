/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findTargetNode(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m,
    TreeNode* target){
        if(!root)
            return NULL;
        if(root == target)
            return target;
        if(root->left)
            m[root->left] = root;
        if(root->right)
            m[root->right] = root;
        findTargetNode(root->left,m,target);
        findTargetNode(root->right,m,target);
        return target;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        if(k==0) return {target->val};
        unordered_map<TreeNode*,int>visited;
        unordered_map<TreeNode*,TreeNode*>m;
        findTargetNode(root,m,target);
        vector<int>v;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty() and k>0){
            int size = q.size();
            for(int i = 0 ; i < size ; ++i){
                TreeNode* head = q.front();
                q.pop();
                if(head->left && visited[head->left] == 0){
                    visited[head->left] = 1;
                    q.push(head->left);
                }
                if(head->right && visited[head->right] == 0){
                    visited[head->right] = 1;
                    q.push(head->right);
                }
                if(m.find(head)!=m.end() && visited[m[head]]==0){
                    visited[m[head]] = 1;
                    q.push(m[head]);
                }
            }
            --k;
        }
        while(!q.empty()){
            if(q.front()->val!=target->val)
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
};