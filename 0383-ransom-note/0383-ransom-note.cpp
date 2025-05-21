class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>m;
        for(int i = 0 ; i<magazine.size() ; ++i){
            m[magazine[i]]++;
        }
        for(int i = 0 ; i<ransomNote.size() ; ++i){
            m[ransomNote[i]]--;
        }
        for(auto it:m){
            if(it.second < 0) return false;
        }
        return true;
    }
};