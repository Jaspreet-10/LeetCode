class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str="";
        int j=0,size=spaces.size();
        for(int i=0;i<s.length();++i){
            if(j<size and i==spaces[j]){
                str+=" ";
                j++;
            }
            str+=s[i];
        }
        return str;
    }
};