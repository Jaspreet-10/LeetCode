class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int left = 0 , right = matrix[0].size(), down = matrix.size(), top = 0;
        while(left<right && top<down){
            for(int i = left ; i < right && top<down ; ++i){
                v.push_back(matrix[top][i]);
            }
            top+=1;
            for(int i = top ; i < down && left<right ; ++i){
                v.push_back(matrix[i][right-1]);
            }
            right-=1;
            for(int i = right-1 ; i >= left && top<down ; --i){
                v.push_back(matrix[down-1][i]);
            }
            down-=1;
            for(int i = down-1 ; i >= top && left<right ; --i){
                v.push_back(matrix[i][left]);
            }
            left+=1;
        }
        return v;
    }
};