class FreqStack {
    int maxCnt = 0;
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> um;
public:
    FreqStack() {}
    
    void push(int val) {
        cnt[val]++;
        maxCnt = max(maxCnt, cnt[val]);
        um[cnt[val]].push(val);
    }
    
    int pop() {
        int x = um[maxCnt].top();
        um[maxCnt].pop();
        if (um[maxCnt].empty())
            maxCnt--;
        cnt[x]--;
        return x;
    }
};