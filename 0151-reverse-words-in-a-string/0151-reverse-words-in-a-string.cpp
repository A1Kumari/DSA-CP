#include <string>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        // Reverse the entire string
        reverse(s.begin(), s.end());

        int start = 0;
        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        // Lambda function to trim leading, trailing spaces, and reduce multiple spaces to a single space
        auto trimAndReduceSpaces = [](std::string& s) {
            int n = s.size();
            int i = 0, j = 0;

            // Skip leading spaces
            while (j < n && s[j] == ' ') j++;

            // Process each character
            while (j < n) {
                // Copy non-space characters
                while (j < n && s[j] != ' ') s[i++] = s[j++];

                // Skip multiple spaces
                while (j < n && s[j] == ' ') j++;

                // Add a single space if there are more characters to process
                if (j < n) s[i++] = ' ';
            }

            // Resize the string to the new length
            s.resize(i);
        };

        // Trim and reduce spaces
        trimAndReduceSpaces(s);

        return s;
    }
};
