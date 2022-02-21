class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1) return {{1}};
        if(n==2) return {{1},{1,1}};
    vector<vector<int>>res{{1},{1,1}};
    vector<int>v={1,1};
    vector<int>ans;
    int i=3;
    ans=v;
    while(i<=n){
        for(int j=0;j<v.size()-1;++j){
            ans.insert(ans.begin()+j+1,v[j]+v[j+1]);
        }
        i++;
        v=ans;
        res.push_back(ans);
        ans={1,1};
    }
    return res;

    }
};