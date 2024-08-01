class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
      vector<int> candlePositions;  // Stores the positions of the candles
    vector<int> result;           // Stores the results for each query

    // Collect the positions of all candles in the string
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '|') {
            candlePositions.push_back(i);
        }
    }

    // Process each query
    for (auto& q : queries) {
        int left = q[0];
        int right = q[1];

        // Find the first candle that is at or after the left boundary
        auto itLeft = lower_bound(candlePositions.begin(), candlePositions.end(), left);

        // Find the last candle that is at or before the right boundary
        auto itRight = upper_bound(candlePositions.begin(), candlePositions.end(), right);
        
        // Move itRight one step back to get the last valid candle within the boundary
        if (itRight != candlePositions.begin()) {
            --itRight;
        } else {
            itRight = candlePositions.end();
        }

        // Check if the left and right candles are valid and if they form a valid range
        if (itLeft != candlePositions.end() && itRight != candlePositions.end() && *itLeft <= *itRight) {
            int leftCandle = *itLeft;
            int rightCandle = *itRight;

            // Calculate the number of plates between the two candles
            int numPlates = rightCandle - leftCandle - (itRight - itLeft);
            result.push_back(numPlates);
        } else {
            result.push_back(0);
        }
    }

    return result;
    }
};