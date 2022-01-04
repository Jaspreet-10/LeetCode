// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n==1) return 1;
        
        // binary search approach
        int l=1; int r= n;
        int index= INT_MAX;
        while(r>=l)
        {
            int m= l+(r-l)/2;
            if(isBadVersion(m))
                //search in the left
                //comare index
            { if(index>m) index=m;
                r= m-1;
             
            }
            else
            {
                //search right
                l=m+1;
            }
        }
        return index;
    }
        
};