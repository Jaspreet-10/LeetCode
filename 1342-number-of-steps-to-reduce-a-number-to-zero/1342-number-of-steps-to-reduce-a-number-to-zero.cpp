class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while(num>0) {
			//Subtract 1 if Odd and Divide by 2 if even
            if(num&1) num-=1;
            else num/=2;
            cnt++;
        }
        return cnt;
    }
};