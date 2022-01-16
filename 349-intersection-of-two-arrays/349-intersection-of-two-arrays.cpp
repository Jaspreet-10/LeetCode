class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<nums1.size();++i){
            m[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();++i){
            if(m[nums2[i]] and m[nums2[i]]!=-1){
                v.push_back(nums2[i]);
                m[nums2[i]]=-1;
            }
        }
        return v;
    }
};