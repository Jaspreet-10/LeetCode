class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int c=0;
        for(int i=0;i<len;i++){
            if(nums[i]==0){
                c++;
            }
        }
        remove(nums.begin(),nums.end(),0);
        for(int i=len-c;i<len;i++){
            nums[i]=0;
        }
    }
};

/*This is the best solution.
int j=0;
for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }

*/