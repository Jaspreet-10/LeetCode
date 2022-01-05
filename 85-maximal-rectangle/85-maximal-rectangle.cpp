class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        int maxA = 0,lenC=M[0].size(),lenR=M.size();
        //cout<<lenC<<" ";
        vector<int>heights(lenC);
        for(int k=0;k<lenR;++k){
            int c=lenC;
            for(int j=0;j<c;++j){
                if(M[k][j]=='1')
                    heights[j]+=1;
                else
                    heights[j]=0;
            }
        int n = heights.size(); 
        stack<int> st; 
        int leftSmall[n], rightSmall[n];
        for(int i = 0;i<n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop(); 
            }
            
            if(st.empty()) leftSmall[i] = 0; 
            else leftSmall[i] = st.top() + 1; 
            st.push(i); 
        }
        
        // clear the stack to be re-used
        while(!st.empty()) st.pop(); 
        
        for(int i = n-1;i>=0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop(); 
            }
            
            if(st.empty()) rightSmall[i] = n-1; 
            else rightSmall[i] = st.top() - 1;
            
            st.push(i); 
        }
        for(int i = 0;i<n;i++) {
            maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
        }
        }
        return maxA;
    }
};