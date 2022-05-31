class Solution {
public:
    void findAllCombs(int openCount,int closeCount,string str,int n,vector<string>&answer){
        if(openCount==closeCount and closeCount==n){
            answer.push_back(str);
            return;
        }
        if(openCount<n)
        findAllCombs(openCount+1,closeCount,str+"(",n,answer);
        if(closeCount<openCount)
        findAllCombs(openCount,closeCount+1,str+")",n,answer);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>answer;
        findAllCombs(0,0,"",n,answer);
        return answer;
    }
};