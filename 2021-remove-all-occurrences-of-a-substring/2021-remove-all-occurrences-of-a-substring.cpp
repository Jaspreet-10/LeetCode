class Solution {
public:
    string removeOccurrences(string s, string part) {
        string str = "";
        for(int i = 0 ; i < s.size() ; ++i){
            str+=s[i];
            if(str.size() >= part.size()){
                if(str.substr(str.size() - part.size()) == part){
                    int k = 0;
                    while(k<part.size()){
                        str.pop_back();
                        ++k;
                    }
                }
            }
        }
        return str;
    }
};