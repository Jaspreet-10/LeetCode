class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    map<string, vector<int>> m;
    vector<string> ans;
    if(keyName.size()<=2) return {};
    for (int i = 0; i < keyName.size(); ++i) {
        m[keyName[i]].push_back(stoi(keyTime[i].substr(0, 2)) * 60 + stoi(keyTime[i].substr(3)));
    }

    for (auto it : m) {
        vector<int> vNum = it.second;
        int cnt = 0;
        sort(vNum.begin(), vNum.end());

        for (int k = 0; k < vNum.size() - 2; ++k) {
            if (vNum[k + 2] - vNum[k] <= 60) {
                ++cnt;
                break;  // Break early if an alert is found
            }
        }

        if (cnt > 0) {
            ans.push_back(it.first);
        }
    }

    sort(ans.begin(), ans.end()); // Sort names alphabetically
    return ans;
    }
};