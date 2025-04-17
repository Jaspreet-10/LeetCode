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
    int cameras = 0;
    int dfs(TreeNode* node) {
        if (!node) return 2; // Null nodes are considered covered

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 0 || right == 0) {
            cameras++;            // Place camera at current node
            return 1;             // This node has a camera
        }

        if (left == 1 || right == 1) {
            return 2;             // This node is covered
        }

        return 0;                 // This node is not covered
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            cameras++;            // Root is not covered, add camera
        }
        return cameras;
    }
};