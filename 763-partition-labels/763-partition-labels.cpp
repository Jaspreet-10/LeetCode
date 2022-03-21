class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> v(26);
        vector<bool> visited(26);
        vector<int> res;
        
        int len = s.size();
        
        for(int i=0;i<len;i++){
            v[s[i] - 'a']++;
            visited[s[i] - 'a'] = false;
        }
        
        int prevLen = 0;
        for(int i=0;i<len;i++){
            v[s[i] - 'a']--;
            visited[s[i] - 'a'] = true;
            
            
            if(v[s[i] - 'a'] == 0){
                //check wheather all the visited chars are 0
                if(isAllVisitedCharAreNull(v, visited)){
                    //Push to result
                    res.push_back(i+1 - prevLen);
                    prevLen = i+1;
                }
            }
        }

        return res;
        
    }
    
    bool isAllVisitedCharAreNull(vector<int>& v, vector<bool>& visited){
        
        bool retVal = false;
        
        for(int i='a';i<='z';i++){
            if(visited[i - 'a'] && v[i - 'a'] == 0){
                retVal = true;
            }else if(visited[i - 'a'] && v[i - 'a'] != 0){
                retVal = false;
                break;
            }
        }
        
        return retVal;
    }
};