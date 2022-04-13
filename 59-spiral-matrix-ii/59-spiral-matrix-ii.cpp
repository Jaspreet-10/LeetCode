class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left=0,right=n-1,top=0,down=n-1,len=(down+1)*(right+1),k=1,matrix[n][n];
        vector<vector<int>>v;
        vector<int>v1;
        while(left<=right and top<=down){
            for(int i=left;i<=right;++i){
                matrix[left][i]=k;
                k++;
            }
            if((len+1)==k)
                break;
            top++;
            for(int i=top;i<=down;++i){
                matrix[i][right]=k;
                k++;
            }
            if((len+1)==k)
                break;
            right--;
            for(int i=right;i>=left;--i){
                matrix[down][i]=k;
                k++;
            }
            if((len+1)==k)
                break;
            down--;
            for(int i=down;i>=top;--i){
                matrix[i][left]=k;
                k++;
            }
            if((len+1)==k)
                break;
            left++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v1.push_back(matrix[i][j]);
            }
            v.push_back(v1);
            v1.clear();
        }
        return v;
    }
};