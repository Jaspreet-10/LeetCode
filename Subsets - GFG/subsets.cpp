// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int totalSubset(int index,vector<int>nums,vector<vector<int>>&ans,vector<int>&bt){
        if(index>=nums.size()){
            ans.push_back(bt);
            return 0;
        }
        bt.push_back(nums[index]);
        totalSubset(index+1,nums,ans,bt);
        bt.pop_back();//This thing is called backtracking. That we are going back..
        totalSubset(index+1,nums,ans,bt);
        return 0;
    }
    vector<vector<int> > subsets(vector<int>&nums)
    {
        vector<vector<int>>ans;
        vector<int>bt;
        totalSubset(0,nums,ans,bt);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends