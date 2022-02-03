class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        vector<vector<int> >res;
        map<vector<int>,int>m;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;++i){
            for(int j=i+1;j<n-2;++j){
                int diff=k-(arr[i]+arr[j]);
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=arr[left]+arr[right];
                    if(sum<diff)
                    left++;
                    else if(sum>diff)
                    right--;
                    else{
                        vector<int>v={arr[i],arr[j],arr[left],arr[right]};
                        left++;
                        right--;
                        if(m[v]==0){
                         res.push_back(v);
                         m[v]++;
                        }
                    }
                }
            }
        }
      return  res;
    }
};