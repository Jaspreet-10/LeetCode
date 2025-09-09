class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;//Dictionary [1,2,3,1]
        for(int i = 0 ; i < nums.size() ; ++i){
            if(m[nums[i]]>0) return true; //m[1] > 0
            m[nums[i]]+=1; //1->1 m[1] = 1, m[2] = 1, m[3] = 1
        }
    return false;
    }
};