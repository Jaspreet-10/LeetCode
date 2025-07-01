class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxi = 0;
        for(int i = 1 ; i < prices.size() ; ++i){
            if(prices[i]>buy){
                maxi = max(maxi, prices[i]-buy);
            }
            if(buy>prices[i]) buy = prices[i];
        }
        return maxi;
    }
};