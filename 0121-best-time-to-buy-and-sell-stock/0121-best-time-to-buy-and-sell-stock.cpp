class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), buy = prices[0], maxi = 0;
        for(int i = 1 ; i < n ; ++i){
            if(prices[i]>buy && prices[i]-buy>maxi){    
                maxi = prices[i]-buy;
            }
            if(prices[i]<buy) buy = prices[i];
        }
        return maxi;
    }
};