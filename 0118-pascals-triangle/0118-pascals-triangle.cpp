class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>>answer = {{1}, {1,1}};
        for(int i = 3 ; i<=numRows ; ++i){
            vector<int>v;
            v.push_back(1);
            for(int j = 0 ; j < answer[i-2].size()-1 ; ++j){
                v.push_back(answer[i-2][j] + answer[i-2][j+1]);
            }
            v.push_back(1);
            answer.push_back(v);
        }
        return answer;
    }
};