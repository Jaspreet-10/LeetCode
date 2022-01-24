class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int r=matrix.size(),c=matrix[0].size();
        vector<int>v;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};