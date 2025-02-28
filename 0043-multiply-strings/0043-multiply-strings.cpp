class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int>res(n1 + n2, 0);
        for(int i = n1-1;i>=0;--i){
            for(int j = n2-1;j>=0;--j){
                cout<<(num1[i]-'0') * (num2[j]-'0')<<" ";
                res[i+j+1]+=(num1[i]-'0') * (num2[j]-'0');
                res[i+j]+= res[i+j+1]/10;
                res[i+j+1]%=10;
            }
        }
        int i = 0;
        string str = "";
        while(res[i] == 0)++i;
        for(int j = i ; j < res.size() ; ++j){
            str+=to_string(res[j]);
        }
        return str;
    }
};