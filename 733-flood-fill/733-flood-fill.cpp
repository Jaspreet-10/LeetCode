class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int rows,int col,int source){
        if(sr<0||sr>=rows||sc<0||sc>=col) 
            return;
        else if(source!=image[sr][sc]) 
            return;
        image[sr][sc]=newColor;
        dfs(image,sr-1,sc,newColor,rows,col,source);
        dfs(image,sr,sc+1,newColor,rows,col,source);
        dfs(image,sr+1,sc,newColor,rows,col,source);
        dfs(image,sr,sc-1,newColor,rows,col,source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows=image.size(),col=image[0].size(),source=image[sr][sc];
        if(image[sr][sc]==newColor) return image;
        dfs(image, sr, sc, newColor,rows,col,source);
        return image;
    }
};