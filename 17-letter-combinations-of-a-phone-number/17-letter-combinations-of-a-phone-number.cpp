class Solution {
public:
    vector<string> letterCombinations(string digits) {
    vector<string> res;
        if(digits.empty()){
            return{};
        }
    res.push_back("");
    map<char,string> map;   
    map={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},          {'9',"wxyz"}};
            for (int i = 0; i <digits.size() ; ++i) {
            if(digits[i]<'2'||digits[i]>'9') {
                    continue;
                    }
            string cand=map[digits[i]];
            vector<string> tmp;
            for (int j = 0; j < cand.size(); ++j) {
            for (int k = 0; k < res.size(); ++k) {
                tmp.push_back(res[k]+cand[j]);
                        }
                    }
                res=tmp;
                tmp.clear();
                }
            return res;
            }   
        };