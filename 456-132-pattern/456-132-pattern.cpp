class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int leftMin[n];
        leftMin[0] = nums[0];
        stack<int>st;
        for(int i = 1 ; i < n ; ++i){
            leftMin[i] = min(leftMin[i-1],nums[i]);
        }
        st.push(nums[n-1]);
        for(int j = n-2 ; j>=0 ; --j){
            if(leftMin[j]<nums[j]){
                while(!st.empty() and st.top()<=leftMin[j]){
                st.pop();
            }
            if(!st.empty() and nums[j]>st.top())
                return true;
            st.push(nums[j]);
            }
        }
        return false;
    }
};