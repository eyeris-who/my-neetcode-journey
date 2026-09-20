// https://neetcode.io/problems/reverse-bits/question

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        cout << result << endl;

        for (int i = 0; i < 32; i++) {
            uint32_t digit = (n >> i) & 1; // shift right to put digit in one's place
            result |= digit << (31-i); // shift left to put digit in bigger place
        }
        return result;
    }
};
