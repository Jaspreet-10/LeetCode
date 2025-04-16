class Solution {
public:
    int n;

    int countIncreasing(int i, int count, int prev, vector<int>& rating, vector<vector<vector<int>>>& dpInc) {
        if (count == 3) return 1;
        if (i == n) return 0;

        if (dpInc[i][count][prev + 1] != -1) return dpInc[i][count][prev + 1];

        int pick = 0;
        if (prev == -1 || rating[i] > rating[prev]) {
            pick = countIncreasing(i + 1, count + 1, i, rating, dpInc);
        }
        int skip = countIncreasing(i + 1, count, prev, rating, dpInc);

        return dpInc[i][count][prev + 1] = pick + skip;
    }

    int countDecreasing(int i, int count, int prev, vector<int>& rating, vector<vector<vector<int>>>& dpDec) {
        if (count == 3) return 1;
        if (i == n) return 0;

        if (dpDec[i][count][prev + 1] != -1) return dpDec[i][count][prev + 1];

        int pick = 0;
        if (prev == -1 || rating[i] < rating[prev]) {
            pick = countDecreasing(i + 1, count + 1, i, rating, dpDec);
        }
        int skip = countDecreasing(i + 1, count, prev, rating, dpDec);

        return dpDec[i][count][prev + 1] = pick + skip;
    }

    int numTeams(vector<int>& rating) {
        n = rating.size();
        vector<vector<vector<int>>> dpInc(n, vector<vector<int>>(4, vector<int>(n + 1, -1)));
        vector<vector<vector<int>>> dpDec(n, vector<vector<int>>(4, vector<int>(n + 1, -1)));

        return countIncreasing(0, 0, -1, rating, dpInc) + countDecreasing(0, 0, -1, rating, dpDec);
    }
};