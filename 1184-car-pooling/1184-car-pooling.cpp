class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>timeline;
        for (auto& trip : trips) {
        int passengers = trip[0];
        int start = trip[1];
        int end = trip[2];

        timeline[start] += passengers;  // people get in
        timeline[end] -= passengers;    // people get out
    }

    int current = 0;

    // Go through all time points in order
    for (auto& time : timeline) {
        current += time.second;  // update number of people in car

        if (current > capacity) {
            return false;  // too many people!
        }
    }

    return true;  // all trips possible without overloading
    }
};