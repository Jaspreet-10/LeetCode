// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
     int totalWays(int index,vector<int>& candidates,vector<int>&bt,vector<vector<int>>&ans,int target){
        if(target==0){
            ans.push_back(bt);
            return 0;
        }
        if(index>=candidates.size())
            return 0;
        if(candidates[index]<=target){
            bt.push_back(candidates[index]);
            totalWays(index,candidates,bt,ans,target-candidates[index]);
            bt.pop_back();
            while (index != candidates.size() - 1 && candidates[index] == candidates[index + 1]){
            index++;
            }
        }
        totalWays(index+1,candidates,bt,ans,target);
        return 0;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int>bt;
        vector<vector<int>>ans;
        map<vector<int>,int>m;
        sort(candidates.begin(),candidates.end());
        totalWays(0,candidates,bt,ans,target);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends