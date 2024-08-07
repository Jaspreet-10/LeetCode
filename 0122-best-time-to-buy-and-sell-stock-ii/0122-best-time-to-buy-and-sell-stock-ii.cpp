class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int maxProfit = 0, buy = INT_MAX, sell = 0;
        for(int i = 0 ; i < prices.size() ; ++i){
            if(prices[i]<buy){
                buy = prices[i];
            }
            if(prices[i]>buy){
                maxProfit +=(prices[i]-buy);
                buy = prices[i];
            }
        }
        return maxProfit;
    }
};