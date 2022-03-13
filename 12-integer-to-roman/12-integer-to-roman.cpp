class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string>mp{{1,"I"},{2,"II"},{3,"III"},{4,"IV"}
        // {5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}
                                };
        string str="";
        while(num>0){
            if(num>=1000){
                str+='M';
                num-=1000;
            }
            else if(num>=900){
                str+="CM";
                num-=900;
            }
            else if(num>=500){
                str+='D';
                num-=500;
            }
            else if(num>=400){
                str+="CD";
                num-=400;
            }
            else if(num>=100){
                str+='C';
                num-=100;
            }
            else if(num>=90){
                str+="XC";
                num-=90;
            }
            else if(num>=50){
                str+='L';
                num-=50;
            }
            else if(num>=40){
                str+="XL";
                num-=40;
            }
            else if(num>=10){
                str+='X';
                num-=10;
            }
            else if(num>=9){
                str+="IX";
                num-=9;
            }
            else if(num>=5){
                str+='V';
                num-=5;
            }
            else{
            str+=mp[num%5];
            num-=(num%5);
            }
        }
        return str;
    }
};