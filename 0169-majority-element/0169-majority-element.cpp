class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m; //dictionary
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; ++i){
            m[nums[i]]+=1;
        }
        for(auto it : m){
            if(it.second>(n/2)) return it.first;
        }
        return 0;
    }
};