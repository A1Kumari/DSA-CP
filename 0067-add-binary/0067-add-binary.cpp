class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int digit_a = (i >= 0) ? a[i] - '0' : 0;
            int digit_b = (j >= 0) ? b[j] - '0' : 0;
            int temp_sum = digit_a + digit_b + carry;
            int result_digit = temp_sum % 2;
            carry = temp_sum / 2;
            result = to_string(result_digit) + result;
            i--;
            j--;
        }

        return result;
    }
};
