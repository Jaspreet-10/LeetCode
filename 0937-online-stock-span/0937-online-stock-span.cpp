class StockSpanner {
public:
    stack<pair<int,int>>st;
    int cnt = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }
        int ans = st.empty()? cnt+1 : cnt - st.top().first;
        st.push({cnt,price});
        ++cnt;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */