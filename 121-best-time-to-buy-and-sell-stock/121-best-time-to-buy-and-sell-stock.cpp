class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp=0,bp=INT_MAX,sp=INT_MIN,max=0;
        for(int i=0;i<prices.size();i++){
            cp=prices[i];
            if(cp<bp){
                bp=cp;
                sp=0;
            }
            if(cp>sp&&cp>bp){
                if(cp-bp>max){
                    sp=cp;
                    max=sp-bp;
                }
            }
        }
        return max;
    }
};