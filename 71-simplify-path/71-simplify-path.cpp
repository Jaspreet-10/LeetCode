class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string result = "";
        if(path =="/") return "/";
        for(int i=0;i<path.size();i++){
            string str = "";
            if(path[i] == '/') continue;
            
            while(i<path.size() && path[i] !='/'){
                str += path[i];
                i++;
            }
            
            if(str == ".." && str != "..."){
                if(!v.empty()){
                    v.pop_back();
                }
            }
            else if(str == "." || str == "") continue;
            else{
                v.push_back(str);
            }
        }
        for(string s:v){
            result +=  '/' + s;
        }
        if(v.empty()) return "/";
        return result;
    }
};