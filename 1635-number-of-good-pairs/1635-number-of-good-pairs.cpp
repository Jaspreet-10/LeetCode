class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int>m;
       int count = 0;
       for(auto it:nums){
            if(m[it]>0) count+=m[it];
            m[it]++;
       }
       return count; 
    }
};