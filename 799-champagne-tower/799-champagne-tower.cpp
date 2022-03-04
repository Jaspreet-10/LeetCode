class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured==0) return 0;
        vector<double>res;
        res.push_back(poured);
        while(query_row-->0){
            vector<double>v;
            v.push_back(max(0.0,((res[0]-1)/2.0)));
            for(int i=1;i<res.size();++i){
                v.push_back(max(0.0,(res[i-1]-1)/2.0)+max(0.0,(res[i]-1)/2.0));
            }
            v.push_back(v[0]);
            res=v;
        }
        return min(1.0,res[query_glass]);
    }
};