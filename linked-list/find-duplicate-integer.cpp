// https://neetcode.io/problems/find-duplicate-integer/question

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for (int i = 0; i < nums.size(); i++) {
            if (check.contains(nums[i])) return nums[i];
            check.insert(nums[i]);
        }
    }

    // stupid real solution
    // goal is to find the beginning of the cycle
    // this is bc there will be dup with beg + end of cycle
    int findDuplicate(vector<int>& nums) {
        // START AT SAME PLACE!!!!!!
        int slow = 0;
        int fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break; // found intersection
        }

        // distance from intersection to beginning of cycle = distance from index 0 to beginning of cycle
        int slow2 = 0;
        while(true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) break;
        }
        return slow;
    }
};
