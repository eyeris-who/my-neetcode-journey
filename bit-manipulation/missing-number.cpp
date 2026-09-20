// https://neetcode.io/problems/missing-number/question

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = len*(len+1)/2;
        for (int i = 0; i < len; i++) {
            sum -= nums[i];
        }
        return sum;
    }

    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i <= nums.size(); i++) {
            result ^= i;
        }

        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};
