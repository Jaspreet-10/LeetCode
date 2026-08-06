class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (m[n] == 0) {
            int num = n, sum = 0;
            m[n]++;
            while (num > 0) {
                int r = num % 10;
                sum = sum + (r * r);
                num /= 10;
            }
            cout << sum << " ";
            if (sum == 1)
                return true;
            n = sum;
        }
        return false;
    }
};