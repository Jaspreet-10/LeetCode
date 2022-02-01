// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length()) 
        return false;
        int m1[256]={0},m2[256]={0};
        for(int i=0;i<str1.length();++i){
        int ch1=str1[i];
        int ch2=str2[i];
        if(m1[str1[i]]==0 and m2[str2[i]]==0){
            m1[ch1]=ch2;
            m2[ch2]=ch1;
        }else if(m1[str1[i]]!=ch2)
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends