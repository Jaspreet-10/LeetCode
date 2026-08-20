class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s = s+s;
        auto it = s.find(goal);
        if(it == string::npos) return false;
        return true;
    }
};