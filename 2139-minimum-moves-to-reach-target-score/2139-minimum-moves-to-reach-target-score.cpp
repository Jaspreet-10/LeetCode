class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        if(maxDoubles==0)
            return target-1;
        while(target>1){
        if(maxDoubles!=0 and target%2==0){
           target/=2;
            maxDoubles-=1;
        }else{
            target-=1;
            }
             ++cnt;
        }
        return cnt;
    }
};