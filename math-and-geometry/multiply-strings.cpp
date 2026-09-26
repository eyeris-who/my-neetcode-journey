// https://neetcode.io/problems/multiply-strings/question

class Solution {
public:
    // multiply v1 by one digit, shifted by place zeros, digits stored least significant first
    void multiplyDigit(int digit, vector<int>& v1, int place, vector<vector<int>>& products) {
        vector<int> product(place, 0);
        int carry = 0;
        for (int i = v1.size()-1; i >= 0; i--) {
            int prod = v1[i]*digit + carry;
            carry = prod / 10;
            int dig = prod % 10;
            product.push_back(dig);
        }
        if (carry) product.push_back(carry);
        products.push_back(product);
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        stringstream s1(num1);
        stringstream s2(num2);
        char num; // read one char at a time so each digit is separate
        vector<int> v1;
        while (s1 >> num) {
            v1.push_back(num - '0');
        }
        vector<int> v2;
        while (s2 >> num) {
            v2.push_back(num - '0');
        }

        int l2 = v2.size();
        vector<vector<int>> products;
        for (int j = l2-1; j >= 0; j--) {
            multiplyDigit(v2[j], v1, l2-1-j, products);
        }

        // add up all the products column by column
        string result;
        int carry = 0;
        int maxLen = products.back().size();
        for (int col = 0; col < maxLen || carry; col++) {
            int sum = carry;
            for (auto& product : products) {
                if (col < product.size()) sum += product[col];
            }
            carry = sum / 10;
            int dig = sum % 10;
            result.push_back('0' + dig);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
