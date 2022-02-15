// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    map<char,int>m;
    int count=0;
    for(int i=0;i<str1.length();++i){
        m[str1[i]]++;
    }
    for(int i=0;i<str2.length();++i){
        m[str2[i]]--;
    }
    for(auto it=m.begin();it!=m.end();++it){
        if(it->second!=0){
        if(it->second<0)
            it->second*=-1;
        count+=it->second;
        }
    }
    return count;
}