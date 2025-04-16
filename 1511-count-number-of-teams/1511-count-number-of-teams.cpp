class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int j = 1; j < n - 1; ++j) {
            int leftSmaller = 0, leftGreater = 0;
            int rightSmaller = 0, rightGreater = 0;

            // Count elements on the left of j
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) leftSmaller++;
                else if (rating[i] > rating[j]) leftGreater++;
            }

            // Count elements on the right of j
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] > rating[j]) rightGreater++;
                else if (rating[k] < rating[j]) rightSmaller++;
            }

            count += (leftSmaller * rightGreater) + (leftGreater * rightSmaller);
        }

        return count;
    }
};