class Solution {
public:
    string simplifyPath(string path) {
    vector<string> result;
    stack<string>s;
    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;
    auto start = 0U;
    auto end = path.find(delimiter);
    while (end != std::string::npos)
    {
        result.push_back(path.substr(start, end - start));
        start = end + delimiter.length();
        end = path.find(delimiter, start);
    }
        result.push_back(path.substr(start, end));
        for(int i=0;i<result.size();++i){
            if(!s.empty() and result[i]=="..") s.pop();
            else if(result[i]!="" and result[i]!="." and result[i]!=".."){
                s.push(result[i]);
            }
        }
        int size=s.size();
        string str="";
        if(s.empty()) return "/";
        for(int i=0;i<size;++i){
            str.insert(0,("/"+s.top()));
            s.pop();
        }
        return str;
    }
};