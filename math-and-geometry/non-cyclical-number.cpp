// https://neetcode.io/problems/non-cyclical-number/question

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while(true) {
            if (n == 1) return true;
            if (nums.count(n)) return false;
            nums.insert(n);
            int sum = 0;
            while(n > 0) {
                int dig = n % 10;
                sum += dig*dig;
                n = n / 10;
            }
            n = sum;
        }
    }
};
