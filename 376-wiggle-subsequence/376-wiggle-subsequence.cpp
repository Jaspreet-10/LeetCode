class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        vector<int>v;
        int cnt = 1,maxi=INT_MIN;
        for(int i = 0 ; i < nums.size()-1;++i){
            if(nums[i+1]-nums[i]!=0){
            v.push_back(nums[i+1]-nums[i]);
            }
        }
        if(v.size()<=1)
            return 1;
        bool flag;
        if(v[0]<0)
            flag = true;
        else
            flag = false;
        for(int i = 1 ; i < v.size() ; ++i){
            if(v[i]>0 and flag==true){
                flag = false;
                ++cnt;
            }
            else if(v[i]<0 and flag==false){
                flag = true;
                ++cnt;
            }
        }
        return cnt+1;
    }
};