// https://neetcode.io/problems/number-of-one-bits/question

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n > 0) {
            int remainder = n % 2;
            result += remainder;
            n = n / 2;
        }
        return result;
    }

    int hammingWeight(uint32_t n) {
        int count = 0;
        // uint32_t means it's a 32-bit int
        for (int i = 0; i < 32; i++) {
            // bit-mask digit
            uint32_t mask = 1 << i;
            if (mask & n) count++;
        }
        return count;
    }

    int hammingWeight(uint32_t n) {
        int count = 0;
        // uint32_t means it's a 32-bit int
        while (n) {
            // bit-mask digit
            uint32_t mask = 1;
            if (mask & n) count++;
            n = n >> 1;
        }
        return count;
    }

    // Subtracting 1 from num flips rightmost 1 bit to 0 and turns all bits to its right into 1
    // Performing n & (n - 1) removes rightmost 1 bit from n
    // n = n & (n - 1) -> eliminate exactly one 1 bit
    int hammingWeight(uint32_t n) {
        int count = 0;
        // uint32_t means it's a 32-bit int
        while (n) {
            // bit-mask digit
            n = n & (n-1);
            count++;
        }
        return count;
    }
};
