class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, maxi = 0;
        for(int i = 0 ; i < prices.size() ; ++i){
            if(prices[i]<buy){
                buy = prices[i];
            }
            maxi = max(maxi, prices[i] - buy);
        }
        return maxi;
    }
};