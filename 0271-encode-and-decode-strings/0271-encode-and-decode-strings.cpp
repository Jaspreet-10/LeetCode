class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0 ; i < strs.size() ; ++i){
            s = s +  to_string(strs[i].size())+ "#" + strs[i];
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
         vector<string>answer;
        for(int i = 0 ; i < s.size() ; ++i){
            int t = 0;
            while(i<s.size() && s[i]!='#'){
                t = t*10 + s[i] - '0';
                ++i;
            }
            answer.push_back(s.substr(i+1, t));
            i+=t;
        }
        return answer;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));