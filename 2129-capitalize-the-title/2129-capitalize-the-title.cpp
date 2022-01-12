class Solution {
public:
    string capitalizeTitle(string s1) {
    string str="";
    int last_index=0;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    for(int i=0;i<s1.length();++i){
        if(s1[i]==' '){
            if(i-last_index>2){
                s1[last_index]=toupper(s1[last_index]);
            }
            last_index=i+1;
        }
        if(i-last_index>=2){
            s1[last_index]=toupper(s1[last_index]);
        }
    }
        return s1;
    }
};