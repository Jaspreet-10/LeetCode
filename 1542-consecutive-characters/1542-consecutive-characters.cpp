class Solution {
public:
    int maxPower(string s) {
        int count = 1, maxi = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] == s[i+1]) ++count;
            else{
                maxi = max(count, maxi);
                count = 1;
            }
        }
        return maxi;
    }
};