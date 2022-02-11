class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        vector<int>arr1(26,0),arr2(26,0);
        int right=0,left=0,size=s2.length();
        for(int i=0;i<s1.length();++i){
            arr1[s1[i]-'a']+=1;
            arr2[s2[i]-'a']+=1;
            right++;
        }
        right-=1;
        while(right<size){
            if(arr1==arr2) return true;
            right+=1;
            if(right<size)
                arr2[s2[right]-'a']+=1;
                arr2[s2[left]-'a']-=1;
            left+=1;
        }
        return false;
    }
};