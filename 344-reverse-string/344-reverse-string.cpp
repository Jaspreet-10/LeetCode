class Solution {
public:
    void reverse_string(int index,int n,vector<char>& s){
        if(index==(n/2-1)){
            swap(s[index],s[n-index-1]);
            return;
        }
        reverse_string(index+1,n,s);
        swap(s[index],s[n-index-1]);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        if(n==1){
            
        }else if(n==2) swap(s[0],s[1]);
        else
        reverse_string(0,n,s);
    }
};