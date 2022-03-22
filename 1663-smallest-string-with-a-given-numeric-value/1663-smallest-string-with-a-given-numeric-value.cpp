class Solution {
public:
    string getSmallestString(int n, int k) {
        string str="";
        stack<char>ch;
        for(int i=n-1;i>=0;--i){
            int val=min(26,k-i);
            ch.push('a'+val-1);
            k=k-val;
        }
        while(!ch.empty()){
            str+=ch.top();
            ch.pop();
        }
        // reverse(str.begin(),str.end());
        return str;
    }
};