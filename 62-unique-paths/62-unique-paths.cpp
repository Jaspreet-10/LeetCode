class Solution {
public:
    int findUniquePaths(int r,int c , int m , int n, map<pair<int,int>,int>&memo){
        // cout<<r<<" "<<c<<"\n";
        if(m-1==r and n-1==c){
            return 1;
        }
        if(r>=m || c>=n){
            return 0;
        }
        pair<int,int> currentKey = {r,c};
        
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        
        int rightMove = findUniquePaths(r,c+1,m,n,memo);
        
        int downMove = findUniquePaths(r+1,c,m,n,memo);
        
        memo[currentKey] = rightMove + downMove;
        
        return rightMove + downMove;
    }
    int uniquePaths(int m, int n) {
        map<pair<int,int>,int>memo;
        return findUniquePaths(0,0,m,n,memo);
    }
};