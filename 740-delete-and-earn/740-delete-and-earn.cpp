class Solution {
public:
int maximumPoints(int index,vector<int>freq,int n,unordered_map<int,int>&memo){
        
        if(index>=n)
            return 0;
        
        int currentKey=index+1;
        
        if(memo[currentKey]>0)
            return memo[currentKey];
        
        int consider=(index*freq[index])+maximumPoints(index+2,freq,n,memo);
        
        int notConsider=maximumPoints(index+1,freq,n,memo);
        
        memo[currentKey]=max(consider,notConsider);
        
        return memo[currentKey];
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>freq(nums[nums.size()-1]+1,0);
        unordered_map<int,int>memo;
        for(int i=0;i<nums.size();++i){
            freq[nums[i]]+=1;
        }
        return maximumPoints(0,freq,nums[nums.size()-1]+1,memo);
    }
};