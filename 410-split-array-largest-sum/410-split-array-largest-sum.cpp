class Solution {
public:
    bool isPossible(vector<int>&arr,int mid,int m){
        int wow = 1;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            
            if(sum>mid){
                wow++;
                sum = arr[i];
            }
        }
        return wow<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int maxx = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxx = max(maxx,nums[i]);
        }
        
        if(m==nums.size()){
            return maxx;
        }
           
        int low = maxx;
        int high = sum;
        int ans = 0;
           
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(nums,mid,m)==true){
                ans = mid;
                high = mid-1;
            }else{
                low =mid+1;
            }
        }
         return ans;
    }
};