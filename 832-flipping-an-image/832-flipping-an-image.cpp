class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();++i){
            for(int j=image[i].size()-1;j>=0;--j){
                if(image[i][j]==0)
                    image[i][j]=1;
                else
                    image[i][j]=0;
            }
            reverse(image[i].begin(),image[i].end());
        }
        return image;
    }
};