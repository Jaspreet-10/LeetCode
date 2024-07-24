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
    TreeNode* findMinNode(TreeNode* currentNode){
        while(currentNode->left!=NULL){
            currentNode = currentNode->left;
        }
        return currentNode;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val>key)
            root->left = deleteNode(root->left,key);
        else if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(!root->left and !root->right){
                root = NULL;
                return root;
            }
        if(root->left and !root->right){
            root = root->left;
            return root;
        }
        if(!root->left and root->right){
            root = root->right;
            return root;
        }
        TreeNode* subsNode = findMinNode(root->right);
        root->val = subsNode->val;
        root->right = deleteNode(root->right,subsNode->val);
        }
        return root;
    }
};