class Solution {
public:
    int binary(vector<int>v,int l, int r, int key,int &flag)
    {
		// till l doesn't exceed r
        if(r >= l)
        {
            int mid = (l+r)/2;
			
            if(key == v[mid]){
                flag=mid;
                return mid;
            }
            else if(key < v[mid]){
                binary(v,l,mid-1,key,flag);
                if(flag!=-1)
                    return flag;
            }
				
            else{
                binary(v,mid+1,r,key,flag);
                if(flag!=-1)
                    return flag;
            }
        }
		
		// if key not found
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int flag=-1;
        return binary(nums,0,nums.size()-1,target,flag);   
    }
	// for github repository link go to my profile.
};