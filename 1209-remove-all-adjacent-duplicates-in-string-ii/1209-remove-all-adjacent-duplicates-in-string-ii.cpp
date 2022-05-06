class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>mainS;
        // mainS.push({s[0],1});
        for(int i = 0 ; i < s.length() ; ++i){
            if(!mainS.empty() and s[i] == mainS.top().first){
                 mainS.top().second= mainS.top().second+1;
            }
            else
            mainS.push({s[i],1});
            if(!mainS.empty() and mainS.top().second == k)
                mainS.pop();
        }
        string res = "";
        while(!mainS.empty()){
            for(int i = 0 ; i < mainS.top().second ; ++i){
                res+=mainS.top().first;
            }
            // res+=mainS.top().first;
            mainS.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};