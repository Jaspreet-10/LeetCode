class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        int lowest=low;
        long long add=1,prod=1,count=2;
        while(low>10){
            add=add*10+1;
            prod=prod*10+count;
            count++;
            low/=10;
        }
        long long prod1=prod;
        cout<<add<<" "<<prod;
        while(prod<=high){
            if(prod>=lowest and prod<=high)
            v.push_back(prod);
            if(count==10)
            break;
            prod+=add;
               if(prod%10==9){
                 if(prod>=lowest and prod<=high)
                v.push_back(prod);
                prod1=prod1*10+count;
                count++;
                add=add*10+1;
                prod=prod1;
            }
        }
        return v;
    }
};