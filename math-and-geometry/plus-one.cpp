// https://neetcode.io/problems/plus-one/question

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = digits[digits.size()-1]+1;
        digits[digits.size()-1] = sum % 10;
        int incr = sum / 10;
        for (int i = digits.size()-2; i >= 0; i--) {
            sum = incr+digits[i];
            digits[i] = sum % 10;
            incr = sum / 10;
        }

        if (incr > 0) {
            for (int i = 0; i < digits.size(); i++) {
                int temp = digits[i];
                digits[i] = incr;
                incr = temp;
            }
            digits.push_back(incr);
        }

        return digits;
    }
};
