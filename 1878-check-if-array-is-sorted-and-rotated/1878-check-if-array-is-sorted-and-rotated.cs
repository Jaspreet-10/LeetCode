public class Solution {
    public bool Check(int[] nums) {
        int [] arr = new int[nums.Length];
        int x = -1;
        for(int i = 0 ; i < nums.Length-1 ; ++i){
            if(nums[i]>nums[i+1]){
                x = nums.Length-(i+1);
                break;
            }
        }
        if(x == -1) return true;
        for(int i = 0 ; i < nums.Length ; ++i){
            arr[(i+x)%nums.Length] = nums[i];
        }
        for(int i = 0 ; i < nums.Length-1 ; ++i){
            if(arr[i]>arr[i+1]) return false;
        }
        return true;
    }
}