class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
    vector<int> nSE(n, 0); // Next Smaller Element
    vector<int> pSE(n, 0); // Previous Smaller Element
    stack<int> st;
    long long sum = 0;
    const int MOD = 1000000007;

    // Calculate Previous Smaller Elements
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        pSE[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    // Clear the stack for reuse
    while (!st.empty()) st.pop();

    // Calculate Next Smaller Elements
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        nSE[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    // Calculate the sum of subarray minimums
    for (int i = 0; i < n; ++i) {
        sum = (sum + (long long)nSE[i] * pSE[i] * arr[i]) % MOD;
    }

    return (int)sum;
    }
};