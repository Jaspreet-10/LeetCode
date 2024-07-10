class Solution {
public:
    vector<vector<int>> res;

void totalSubsets(vector<int>& nums, vector<int>& v, int index) {
    // Base case: if the index is greater than or equal to the size of nums, push the current subset
    if (index >= nums.size()) {
        res.push_back(v);
        return;
    }
    
    // Recursive case 1: Do not take the current index element
    totalSubsets(nums, v, index + 1);
    
    // Recursive case 2: Take the current index element
    v.push_back(nums[index]);
    totalSubsets(nums, v, index + 1);
    
    // Backtrack by removing the last element
    v.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> v;
    res.clear(); // Clear the result vector before starting
    totalSubsets(nums, v, 0);
    return res;
}
};