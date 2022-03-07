class Solution {
public:
    string longestPrefix(string s) {
        int i=0,j=1,len=s.length();
        if(len==1) return "";
        int a[len];
        a[0]=0;
        string str="";
            while(i<len and j<len){
                if(s[i]!=s[j]){
                    if(i==0){
                        a[j]=0;
                        j++;
                    }
                    else{
                        i=a[i-1];
                    }
                }else{
                    a[j]=i+1;
                    i++;
                    j++;
                }
            }
        if(a[len-1]==0)
            return str;
        for(int i=0;i<a[len-1];++i)
        str+=s[i];
        return str;
        }
    };