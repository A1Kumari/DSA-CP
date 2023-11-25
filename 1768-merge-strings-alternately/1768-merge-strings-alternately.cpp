#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int maximum = max(n, m);

        string ans;
        for(int i = 0; i < maximum; i++) {
            if(i < n) {
                ans.push_back(word1[i]);
            }
            if(i < m) {
                ans.push_back(word2[i]);
            }
        }
        return ans;
    }
};
