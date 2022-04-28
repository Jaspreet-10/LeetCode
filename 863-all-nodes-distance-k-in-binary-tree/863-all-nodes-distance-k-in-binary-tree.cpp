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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>map;
        unordered_map<TreeNode*,int>visited;
        while(!q.empty()){
            int size = q.size();
            for(int i = size-1;i>=0;--i){
                TreeNode *head = q.front();
                q.pop();
                if(head->left){
                    map[head->left] = head;
                    q.push(head->left);   
                }
                if(head->right){
                   map[head->right] = head;
                   q.push(head->right);   
                }
            }
        }
        q.push(target);
        visited[target] = 1;
        int distance = 0;
        while(distance<k){
            int size = q.size();
            for(int i = size-1;i>=0;--i){
                TreeNode* head = q.front();
                q.pop();
                if(map[head] and visited[map[head]]==0){
                    visited[map[head]] = 1;
                    q.push(map[head]);
                }
                if(head->left and visited[head->left]==0){
                    visited[head->left] = 1;
                    q.push(head->left);
                }
                if(head->right and visited[head->right]==0){
                    visited[head->right] = 1;
                    q.push(head->right);
                }
            }
            ++distance;
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};