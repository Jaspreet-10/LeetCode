class Solution {
public:
    void _merge(vector<int>& nums, int low, int mid, int high, int &countPairs) {
    int leftInd = low, rightInd = mid+1, r = rightInd, temp[high-low+1], tempInd = 0, counter = 0;
    while(leftInd<=mid) {
        while( r<=high && (nums[leftInd] > (long)2*nums[r]) ) counter++, r++;
        countPairs+= counter;
        while( rightInd<=high && nums[rightInd]<=nums[leftInd] ) {
            temp[tempInd++] = nums[rightInd++];
        }
        temp[tempInd++] = nums[leftInd++];
    }
    while(rightInd<=high) {
        temp[tempInd++] = nums[rightInd++];
    }
    for(int i=0; i<tempInd; i++) 
        nums[low++] = temp[i];
    }    
    int mergeSort(int low,int high,int &countPairs,vector<int>&nums){
        if(low<high){
            int middle = low+(high-low)/2;
            mergeSort(low,middle,countPairs,nums);
            mergeSort(middle+1,high,countPairs,nums);
            _merge(nums,low,middle,high,countPairs);
        }
        return countPairs;
    }
    int reversePairs(vector<int>& nums) {
        int low = 0 , high = nums.size(),countPairs = 0,mid = 0;
        mergeSort(low,high-1,countPairs,nums);
        return countPairs;
    }
};