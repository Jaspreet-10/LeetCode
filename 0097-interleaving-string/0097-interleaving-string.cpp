class Solution {
public:
  bool checkIsInterleave(string s1, string s2, string s3, int len1, int len2, int len3,
   int i1, int i2, int i3, map<pair<pair<int,int>,int>,bool>&m) {
    // Base cases
    if (i3 == len3) return (i1 == len1 && i2 == len2);
    bool ans = false;
    if(m.find({{i1,i2},i3})!=m.end()) return m[{{i1,i2},i3}];
    if (i1 < len1 && s1[i1] == s3[i3]) {
        ans = checkIsInterleave(s1, s2, s3, len1, len2, len3, i1 + 1, i2, i3 + 1,m);
    }
    if (i2 < len2 && s2[i2] == s3[i3]) {
        ans = ans || checkIsInterleave(s1, s2, s3, len1, len2, len3, i1, i2 + 1, i3 + 1,m);
    }
    m[{{i1,i2},i3}] = ans;
    return ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();
    map<pair<pair<int,int>,int>,bool>m;
    if (len1 + len2 != len3) return false;

    return checkIsInterleave(s1, s2, s3, len1, len2, len3, 0, 0, 0,m);
    }
};