class Solution {
public:
    int lengthOfLongestSubstring(string str) {
    unordered_map<char,int>memo;
    int j = 0,res=0;
    for(int i=0;i<str.length();++i){
        if(memo[str[i]]==0){
            memo[str[i]]++;
        }else{
            while(memo[str[i]]>0){
                memo[str[j]]--;
                j++;
            }
            memo[str[i]]++;
        }
        res = max(res,i-j+1);
    }
        return res;
    }
};