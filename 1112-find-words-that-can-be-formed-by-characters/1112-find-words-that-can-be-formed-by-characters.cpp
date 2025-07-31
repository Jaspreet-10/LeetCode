class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int>m, temp;
        int count = 0;
        for(int i = 0 ; i < chars.size() ; ++i){
            m[chars[i]]++;
        }
        temp = m;
        for(int i = 0 ; i < words.size() ; ++i){
            m = temp;
            int len = words[i].size(), j = 0;
            for(j = 0 ; j < len ; ++j){
                if(m[words[i][j]] == 0) break;
                m[words[i][j]]--;
            }
            if(j==len) count+=len;
        }
        return count;
    }
};