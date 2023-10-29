class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        for(int i = 0 ; i < bills.size() ; ++i){
            if(bills[i] == 5 or bills[i] == 10)
            m[bills[i]]++;
            if(bills[i] == 5) continue;
            else if(bills[i] == 10 and m[5]>=1){
                m[5]--;
            }
            else if(bills[i] == 20){
                if(m[10]>=1 && m[5]>=1){
                    m[10]-=1;
                    m[5]-=1;
                }else if(m[5]>=3){
                    m[5]-=3;
                }else return false;
            }
            else{
                cout<<i<<" ";
                return false;
            }
        }
        return true;
    }
};