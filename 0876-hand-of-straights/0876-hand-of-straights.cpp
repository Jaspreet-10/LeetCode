class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       map<int,int>m;
       if(hand.size()%groupSize!=0) return false;
       for(int i = 0 ; i < hand.size() ; ++i) m[hand[i]]++;
       while(m.size()>0){
            auto it = m.begin();
            int key = it->first;
            int k = 0;
            while(k<groupSize){
                if(m[key]>0){
                    m[key]--;
                    if(m[key] == 0) m.erase(key);
                    ++key;
                }else
                    return false;
                ++k;
            }
        }
        if(m.size()!=0)
        return false;
        return true;
    }
};