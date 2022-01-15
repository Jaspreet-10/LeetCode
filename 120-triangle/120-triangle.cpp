class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
     vector<int>v;
        int row=triangle.size(),sum=0;;
        for(int i=0;i<triangle[row-1].size();++i){
            v.push_back(triangle[row-1][i]);
        }
        for(int i=row-2;i>=0;--i){
            for(int j=0;j<triangle[i].size();++j){
                v[j]=min(v[j]+triangle[i][j],v[j+1]+triangle[i][j]);
            }
        }
        return v[0];
    }
};