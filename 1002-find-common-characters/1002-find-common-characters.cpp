class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        unordered_map<char,int>map,level;
        int cnt = 1;
        for(int i = 0 ; i < words[0].size() ; ++i){
            map[words[0][i]]++;
            // cout<<
        }
        for(int i = 1 ; i < words.size() ; ++i){
                cnt+=1;
                unordered_map<char,int>temp;
            for(int j = 0 ; j < words[i].size() ; ++j){
                temp[words[i][j]]++;
            }
            for(auto it:map){
                if(it.second>0){
                    map[it.first] = min(it.second,temp[it.first]);
                    // cout<<it.first<<" "<<map[it.first]<<"\n";
                    level[it.first] = cnt;
                }
            }
        }
        vector<string>v;
        for(auto it:map){
            // cout<<it.first<<" "<<it.second<<" "<<level[it.first]<<"\n";
            if(it.second>0 and level[it.first]==words.size()){
            for(int j = 0 ; j < it.second; ++j){
                string str="";
                str+=it.first;
                v.push_back(str);   
                }
            }
        }
        return v;
    }
};