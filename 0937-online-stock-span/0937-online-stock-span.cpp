class StockSpanner {
public:
    stack<pair<int,int>>st;
    int index = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }
        int ans = st.empty()? index+1 : index - st.top().first;
        st.push({index++,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */