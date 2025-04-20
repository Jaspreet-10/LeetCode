class Solution {
public:
    int dfs(vector<int>& debt, int start) {
        while (start < debt.size() && debt[start] == 0)
            start++;  // Skip settled debts
        if (start == debt.size())
            return 0;

        int res = INT_MAX;
        for (int i = start + 1; i < debt.size(); ++i) {
            if (debt[start] * debt[i] < 0) { // One owes, one is owed
                debt[i] += debt[start];
                res = min(res, 1 + dfs(debt, start + 1));
                debt[i] -= debt[start]; // backtrack
            }
        }
        return res;
    }

    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (auto& t : transactions) {
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }

        vector<int> debt;
        for (auto& it : balance)
            if (it.second != 0)
                debt.push_back(it.second);

        return dfs(debt, 0);
    }
};
