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
    vector<int>v;
    void preorder_root1(TreeNode* root1){
            if(root1==NULL) return;
            preorder_root1(root1->left);
            v.push_back(root1->val);
            preorder_root1(root1->right);
        }
    void preorder_root2(TreeNode* root2){
            if(root2==NULL) return;
            preorder_root2(root2->left);
            v.push_back(root2->val);
            preorder_root2(root2->right);
        }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preorder_root1(root1);
        preorder_root2(root2);
        sort(v.begin(),v.end());
        return v;
    }
};