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
        for (auto it : m) {
            int x = it.first.first, y = it.first.second;
            int px = point[0], py = point[1];

            // Check if we have the same x or y coordinate
            if (abs(x - px) != abs(y - py) || x == px || y == py) {
                continue;
            }
            
            // Check if the other two points of the square exist
            if (m.find({x, py}) != m.end() && m.find({px, y}) != m.end()) {
                ans += m[{x, py}] * m[{px, y}] * it.second;
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