class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // going to solve this question using GAP method and call it Shell Sort as well
        int j = 0;
        for(int i = m ; i < m+n ; ++i){
            nums1[i] = nums2[j++];
        }
        int gap = ceil((double)(n+m)/2.0);
        while(gap>0){
            int left = 0, right = gap;
            while(right<m+n){
                if(nums1[left]>=nums1[right]) swap(nums1[left],nums1[right]);
                ++left,++right;
            }
            if(gap == 1) break;
            else
            gap = ceil((double)gap/2.0);

            cout<<gap<<" ";
        }
        return;
    }
};