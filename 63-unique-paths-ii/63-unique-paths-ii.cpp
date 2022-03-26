class Solution {
public:
    int findUniquePaths(int r,int c,int m,int n,vector<vector<int>>& obstacleGrid,map<pair<int,int>,int>&memo){
        if(r>=m || c>=n || obstacleGrid[r][c]==1)
            return 0;
        if(r==m-1 and c==n-1)
            return 1;
        
        pair<int,int> currentKey = {r,c};
        
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        
        int rightMove = findUniquePaths(r,c+1,m,n,obstacleGrid,memo);
        
        int downMove = findUniquePaths(r+1,c,m,n,obstacleGrid,memo);
        
        memo[currentKey] = rightMove + downMove;
        
        return rightMove + downMove;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)     {
        map<pair<int,int>,int>memo;
        return findUniquePaths(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid,memo);
    }
};