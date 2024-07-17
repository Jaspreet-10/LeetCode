class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    vector<int> nSE(n), nGE(n), pSE(n), pGE(n);
    stack<int> st;
    long long sum = 0;

    // Calculate previous smaller element distances
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        pSE[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Clear stack for reuse
    while (!st.empty()) st.pop();

    // Calculate next smaller element distances
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
        nSE[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    // Clear stack for reuse
    while (!st.empty()) st.pop();

    // Calculate previous greater element distances
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        pGE[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Clear stack for reuse
    while (!st.empty()) st.pop();

    // Calculate next greater element distances
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
        nGE[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    // Compute the sum of ranges
    for (int i = 0; i < n; ++i) {
        long long maxContribution = (long long) nums[i] * pGE[i] * nGE[i];
        long long minContribution = (long long) nums[i] * pSE[i] * nSE[i];
        sum += maxContribution - minContribution;
    }

    return sum;
    }
};