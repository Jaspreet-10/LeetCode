class Solution {
public:
    bool detectCapitalUse(string words) {
        if(words.length()==1)
            return true;
        int first=words[0],second=words[1];
        if(first>=97 and first<=122 and second>=65 and second<=90){
            return false;
        }
        else if(first>=65 and first<=90 and second>=65 and second<=90){
            for(int i=2;i<words.length();++i){
                int r=words[i];
                if(r<65 || r>90)
                    return false;
            }
        }
        else if((first>=65 and first<=90) and (second>=97 and second<=122)){
            for(int i=2;i<words.length();++i){
                int r=words[i];
                if(r<97 || r>122)
                    return false;
            }
        }
        else if(first>=97 and first<=122 and second>=97 and second<=122){
            for(int i=2;i<words.length();++i){
                int r=words[i];
                if(r<97 || r>122)
                    return false;
            }
        }
        return true;
    }
};