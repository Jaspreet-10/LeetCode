class Solution {
public:
   void solve(string input,string op,vector<string>&v){
        if(input.empty()){
            // cout<<op<<" ";
            v.push_back(op);
            return ;
        }
        if(isalpha(input[0])){
            string op1=op;
            string op2=op;
            op1.push_back(tolower(input[0]));
            op2.push_back(toupper(input[0]));
            input.erase(input.begin()+0);
            solve(input,op1,v);
            solve(input,op2,v);
        }else{
            string op1=op;
            op1.push_back(input[0]);
            input.erase(input.begin()+0);
            solve(input,op1,v);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>v;
        string op="";
        if(s.length()==0){
            v.push_back(op);
            return v;
        }
        string input=s;
        solve(input,op,v);
        return v;
    }
};