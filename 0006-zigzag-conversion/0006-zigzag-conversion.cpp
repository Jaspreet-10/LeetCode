class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows)
        return s;

    vector<vector<char>> v(numRows);
    int i = 0, row = 0;
    bool down = true;

    while (i < s.size()) {
        v[row].push_back(s[i]);
        ++i;

        if (down) {
            ++row;
            if (row == numRows - 1) down = false;
        } else {
            --row;
            if (row == 0) down = true;
        }
    }

    string result = "";
    for (int i = 0; i < numRows; ++i) {
        for (char c : v[i])
            result += c;
    }

    return result;
    }
};