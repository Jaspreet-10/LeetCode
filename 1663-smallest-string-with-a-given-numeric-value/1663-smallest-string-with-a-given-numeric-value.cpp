class Solution {
public:
    string getSmallestString(int n, int k) {
        string str="";
        for(int i=n-1;i>=0;--i){
            int val=min(26,k-i);
            str+='a'+val-1;
            k=k-val;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};