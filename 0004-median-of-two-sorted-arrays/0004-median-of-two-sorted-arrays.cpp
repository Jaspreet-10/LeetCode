class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int add=nums1.size()+nums2.size();
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        if(add%2!=0){
            return(nums1[((add+1)/2.0)-1]);
        }else{
            return ((nums1[(add/2)-1]+nums1[(add/2)])/2.0);
        }
        return 0;
    }
};