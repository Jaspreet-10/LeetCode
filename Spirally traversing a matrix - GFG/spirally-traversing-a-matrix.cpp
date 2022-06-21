// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>v;
        if(matrix.size()==0){
            return v;
        }
        int left=0, right=c-1, top=0, down=r-1,k=0;
        while(top<=down&&left<=right){
        for(int i=left;i<=right;i++){
            if(matrix[top][i]!=-1)
            v.push_back(matrix[top][i]);
            matrix[top][i]=-1;
            k++;
         }
         top+=1;
        for(int i=top;i<=down;i++){
            if(matrix[i][right]!=-1)
            v.push_back(matrix[i][right]);
            matrix[i][right]=-1;
            k++;
        }
        right-=1;
        for(int i=right;i>=left;i--){
            if(matrix[down][i]!=-1)
            v.push_back(matrix[down][i]);    
            matrix[down][i]=-1;
            k++;
        }
        down-=1;
        for(int i=down;i>=top;i--){
            if(matrix[i][left]!=-1)
            v.push_back(matrix[i][left]);
            matrix[i][left]=-1;
            k++;
            }
            left+=1;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends