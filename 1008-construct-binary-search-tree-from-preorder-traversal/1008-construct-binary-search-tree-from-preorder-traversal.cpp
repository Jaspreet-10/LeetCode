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
    TreeNode* buildTree(vector<int>&preOrder,int&index,int boundVal){
        if(index>=preOrder.size() || preOrder[index]>boundVal)
            return NULL;
        TreeNode* newNode = new TreeNode(preOrder[index]);
        index+=1;
        newNode->left = buildTree(preOrder,index,newNode->val);
        newNode->right = buildTree(preOrder,index,boundVal);
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int index = 0;
      return buildTree(preorder,index,1001);
    }
};