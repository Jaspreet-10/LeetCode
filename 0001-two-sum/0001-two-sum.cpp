class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(m[target-nums[i]]>0){
                return {m[target-nums[i]]-1,i};
            }
            m[nums[i]] = i+1;
        }
        return {};
    }
};

/*
Ask question, is the array sorted and do they have the negative values in the array(map approach will work with negative values as well)
First apply brute force apporach which will take - O(N^2), second is sort the array as and apply two pointers, at the end apply the unordered map approach*/