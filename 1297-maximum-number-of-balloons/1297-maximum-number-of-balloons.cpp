class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        int mini = INT_MAX;
        for(int i = 0 ; i < text.size() ; ++i){
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n'){
                m[text[i]]++;
            }
        }
        if(m.size()!=5) return 0;
        for(auto it:m){
            if(it.first == 'l' || it.first == 'o'){
                mini = min(mini, it.second/2);
            }else{
                 mini = min(mini, it.second);
            }
        }
        return mini;
    }
};