class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
    vector<int> res;
    int n = asteroids.size();

    for (int i = 0; i < n; ++i) {
        bool exploded = false;
        while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
            if (st.top() < abs(asteroids[i])) {
                st.pop();
                continue;
            } else if (st.top() == abs(asteroids[i])) {
                st.pop();
                exploded = true;
                break;
            } else {
                exploded = true;
                break;
            }
        }
        if (!exploded) {
            st.push(asteroids[i]);
        }
    }

    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
    }
};