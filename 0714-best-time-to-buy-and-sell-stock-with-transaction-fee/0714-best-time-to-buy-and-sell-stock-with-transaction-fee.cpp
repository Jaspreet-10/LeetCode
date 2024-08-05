class Solution {
public:
     int bestTrans(vector<int>&prices,int curr,bool canbuy,vector<vector<int>>&vec, int fee)
    {
        
        if(curr>=prices.size()) return 0;
        if(vec[curr][canbuy]!=-1) return vec[curr][canbuy];
        if(canbuy)
        {
            int idle = bestTrans(prices,curr+1,canbuy,vec,fee); 
            int buy = -prices[curr]+bestTrans(prices,curr+1,!canbuy,vec,fee);
            return vec[curr][canbuy]=max(idle,buy);
        }
        else{
            int idle1 = bestTrans(prices,curr+1,canbuy,vec,fee);
            int sell = prices[curr]+bestTrans(prices,curr,canbuy+1,vec,fee) - fee;
            return vec[curr][canbuy]=max(idle1,sell);
        }
        
    }
    int maxProfit(vector<int>& prices, int fee) {
      vector<vector<int>>vec(prices.size(),vector<int>(2,-1));
        return bestTrans(prices,0,1,vec,fee);
    }
};