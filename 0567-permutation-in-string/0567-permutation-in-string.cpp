class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>charArray1(26,0), charArray2(26,0);
        for(int i = 0 ; i < s1.size() ; ++i) charArray1[s1[i] - 'a']++;
        int i = 0, j = 0;
        while(j<s2.size()){
            charArray2[s2[j]-'a']++;
            if(charArray2 == charArray1) return true;
            while((j-i+1)>=s1.size()){
                charArray2[s2[i]-'a']--;
                ++i;
            }
            ++j;
        }
        return false;
    }
};