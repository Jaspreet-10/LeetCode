class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>>res = {{1},{1,1}};
        for(int i = 2 ; i < numRows ; ++i){
            vector<int>tmp;
            tmp.push_back(res[i-1][0]);
            int j = 0;
            for(j = 0 ; j < res[i-1].size()-1 ; ++j){
                tmp.push_back(res[i-1][j]+res[i-1][j+1]);
            }
            tmp.push_back(res[i-1][j]);
            res.push_back(tmp);
        }
        return res;
    }
};