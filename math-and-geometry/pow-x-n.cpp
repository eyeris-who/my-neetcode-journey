// https://neetcode.io/problems/pow-x-n/question

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;
        
        double sqroot = myPow(x, abs(n/2));
        double result = sqroot * sqroot;
        if (abs(n) % 2 == 1) result *= x;
        if (n < 0) result = 1/result;
        return result;
    }
};
