class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     vector<int>ans;
      int mid = n , i = 0;
      bool flag = true;
      while(mid<nums.size()){
          if(flag==true){
              ans.push_back(nums[i]);
              ++i;
              flag = false;
          }else{
              ans.push_back(nums[mid]);
              flag = true;
              ++mid;
              }
            }
        return ans;
    }
};