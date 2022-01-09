class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>m1(26,0),m2(26,0);
        int size1=s1.length(),size2=s2.length(),right=0,left=0;
        if(size2<size1)
            return false;
        for(int i=0;i<size1;++i) {
            m1[s1[i]-'a']+=1;
            m2[s2[i]-'a']+=1;
            right++;
        }
        right-=1;
        while(right<size2){
            if(m1==m2) 
                return true;
            right+=1;
            if(right!=size2)
                m2[s2[right]-'a']++;
                m2[s2[left]-'a']--;
                left+=1;
        }  
        return false;
    }
};