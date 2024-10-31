public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] ans = new int[2];
        Dictionary<int, int> d = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; ++i)
        {
            d[nums[i]] = i;
        }
        for (int i = 0; i < nums.Length; ++i)
        {
            int complement = target - nums[i];

            if (d.ContainsKey(complement) && d[complement] != i)
            {
                ans[0] = i;
                ans[1] = d[complement];
                return ans;
            }
        }
        return new int[] { -1, -1 };
    }
}