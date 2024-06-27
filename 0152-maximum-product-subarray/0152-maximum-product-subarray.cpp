class Solution {
public:
    int maxProduct(vector<int>& nums) {
    double leftSum = 1, rightSum = 1;
    int left = 0, right = nums.size() - 1;
    double maxi1 = -DBL_MAX, maxi2 = -DBL_MAX;

    while (left < nums.size() && right >= 0) {
        maxi2 = std::max(maxi2, std::max((double)nums[left], (double)nums[right]));
        maxi1 = std::max(maxi1, std::max(leftSum * nums[left], rightSum * nums[right]));
        leftSum = nums[left] * leftSum;
        rightSum = nums[right] * rightSum;
        // Reset if the product is zero
        if (leftSum == 0) leftSum = 1;
        if (rightSum == 0) rightSum = 1;
        
        ++left;
        --right;
    }
    cout<<maxi2<<" "<<maxi1<<" ";
    cout<<(int)(std::max(maxi1, maxi2));
    return (int)(std::max(maxi1, maxi2));
    }
};