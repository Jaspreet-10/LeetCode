class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxi = 0;
        for(int i = 1 ; i < prices.size() ; ++i){
            if(prices[i]>buy and prices[i]-buy){
                maxi+=prices[i]-buy;
                buy = prices[i];
            }
            if(prices[i]<buy){
                buy = prices[i];
            }
        }
        return maxi;
    }
};