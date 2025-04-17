class Solution {
public:
    string betterCompression(string compressed) {
        map<char,long long>m;
        string answer = "";
        for(int i = 0 ; i < compressed.size() ; i++){
            char key = compressed[i];
            ++i;
            int ch = compressed[i] - '0';
            long long sum = 0;
            while(ch>=0 && ch<=9){
                sum = sum*10+ch;
                ++i;
                ch = compressed[i] - '0';
            }
            if(m.find(key)!=m.end()){
                m[key] = (long long)(m[key] + sum);
            }
            else m[key] = sum;
            --i;
        }
        for(auto it:m){
            answer+=it.first+to_string(it.second);
        }
        return answer;
    }
};