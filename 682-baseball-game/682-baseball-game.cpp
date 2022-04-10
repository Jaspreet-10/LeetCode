class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        vector<int>scores;
        for (int i = 0; i < ops.size(); ++i)
        {
            if (ops[i] == "+")
                scores.push_back(scores.back() + scores[scores.size()-2]);
            else if (ops[i] == "D")
                scores.push_back(scores.back()*2);
            else if (ops[i] == "C")
                scores.pop_back();
            else //assumed to be a score
                scores.push_back(stoi(ops[i]));
        }

        for (int i = 0; i < scores.size(); ++i)
            score += scores[i];
        return score;
    }
};