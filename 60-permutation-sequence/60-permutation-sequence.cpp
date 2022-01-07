class Solution {
public:
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1;i<=n;++i){
            str+=to_string(i);
        }
        int count=0;
        do{
            count++;
            if(count==k)
                return str;
        }while(next_permutation(str.begin(),str.end()));
        return str;
    }
};