class Solution {
public:
     vector<vector<int>>dfs(vector<vector<int>>& image,int sr,int sc,int color,int row,int col,int initial){
        if(sr<0 || sc<0 || sr>=row || sc>=col || image[sr][sc] == color || image[sr][sc]!=initial)
            return image;
        image[sr][sc] = color;
        dfs(image,sr-1,sc,color,row,col,initial);
        dfs(image,sr+1,sc,color,row,col,initial);
        dfs(image,sr,sc-1,color,row,col,initial);
        dfs(image,sr,sc+1,color,row,col,initial);
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size(), c = image[0].size(),initial = image[sr][sc];
        return dfs(image,sr,sc,color,r,c,initial);
    }
};