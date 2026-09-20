// https://neetcode.io/problems/counting-bits/question

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) return result;
        result.push_back(1);
        if (n == 1) return result;

        int sub = 2;
        int count = 0;
        for (int i = 2; i <= n; i++) {
            if (count == sub) {
                sub *= 2;
                count = 0;
            }
            result.push_back(1+result[i-sub]);
            count++;
        }
        return result;
    }
};
