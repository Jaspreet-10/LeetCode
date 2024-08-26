class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1, c = 0, i = n;
        if(digits[n]+1>=10){
            c = 1;
            while(i>=0 && c>0){
                int sum = digits[i]+c;
                int rem = sum%10;
                c = sum/10;
                digits[i] = rem;
                --i;
            }
            if(c>=1) digits.insert(digits.begin(),1);
        }else{
            digits[n]+=1;
        }
        return digits;
    }
};