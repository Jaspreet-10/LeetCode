class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v(2);
        int n=numbers.size();
        for(int i=0;i<n;++i){
            int low=i,high=n-1;
            while(low<high){
            int sum=numbers[low]+numbers[high];
            if(sum>target)
                high--;
            else if(sum<target)
                low++;
            else    {
                v[0]=low+1;
                v[1]=high+1;
                return v;
                }
            }
        }
        return v;
    }
};

/*
Should solve by this because it is a problem of tw pointers.
int l = 0;
    int r = numbers.size() -1;
   
    while(l < r){
        if(numbers[l] + numbers[r] == target){
           
            return {l+1,r+1};;
        }
        else if(numbers[l] + numbers[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
	return {};
}
*/