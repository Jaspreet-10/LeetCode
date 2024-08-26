class DetectSquares {
public:
    map<pair<int,int>,int>m;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int px = point[0], py = point[1];
        for(auto it : m){
            int x = it.first.first;
            int y = it.first.second;
            if(abs(px-x)!=abs(py-y) || x == px || y == py) continue;
            if(m.find({px,y})!=m.end() && m.find({x,py})!=m.end()){
                ans+=m[{x,py}]*m[{px,y}]*it.second;
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */