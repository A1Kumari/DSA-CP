class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        unordered_map<char, int> freq1,freq2;
        unordered_set<char> chars1, chars2;

        if(n!=m){
            return false;
        }

        for(char c:word1){
            freq1[c]++;
            chars1.insert(c);
        }
        for(char c:word2){
            freq2[c]++;
            chars2.insert(c);
        }
        if(chars1 != chars2){
            return false;
        }

        vector<int> counts1, counts2;
        for(const auto& entry : freq1){
            counts1.push_back(entry.second);
        }
        for(const auto& entry : freq2){
            counts2.push_back(entry.second);
        }

        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};