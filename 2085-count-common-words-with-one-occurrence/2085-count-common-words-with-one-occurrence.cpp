class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>m;
        int cnt = 0;
        for(int i = 0 ; i < words1.size() ; ++i){
                m[words1[i]]++;    
        }
        for(int i = 0 ; i < words2.size() ; ++i){
               if(m[words2[i]]<=1)
                m[words2[i]]--;
        }
        for(auto it:m){
            if(it.second == 0)
                ++cnt;
        }
        return cnt;
    }
};