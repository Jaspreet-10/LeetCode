class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n ; ++i){
              unordered_map<int, int>mr, mc;
            for(int j = 0 ; j < n ; ++j){
               mr[matrix[i][j]]++;
               mc[matrix[j][i]]++;
            }
            if(mr.size()!=n || mc.size()!=n) return false;
        }
        return true;
    }
};