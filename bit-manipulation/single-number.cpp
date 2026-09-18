// https://neetcode.io/problems/single-number/question

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // When two identical numbers are XORed, they cancel out, resulting in zero !!!!!
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};
