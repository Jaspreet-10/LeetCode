class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        my_dict = {}
        for i in range(0, len(nums)):
            if my_dict.get(nums[i], 0) > 0:
                return True
            my_dict[nums[i]] = my_dict.get(nums[i], 0) + 1
        return False

        