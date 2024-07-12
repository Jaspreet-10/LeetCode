class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0 , count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
                    nums[count] = nums[i];    
                    count++;
                for( j = i ; j < nums.size() ; j++){
                        if(nums[i]!=nums[j]){
                            break;
                        }
                }
                i = j - 1;
             }
        return count;
    }
};