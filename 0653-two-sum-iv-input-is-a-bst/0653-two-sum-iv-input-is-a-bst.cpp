class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inOrder(root, nums);  // Get sorted elements

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) return true;
            else if (sum < k) ++left;
            else --right;
        }
        return false;
    }
};
