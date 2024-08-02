class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            m[nums[i]]++;
        }
        for(auto it : m){
                 while(it.second>=2){
                   if(it.second%3 == 0) it.second-=3;
                   else it.second-=2;
                   ++cnt;
                }
                if(it.second>0){ 
                    return -1;
                }
            }
            return cnt;
        }
    };