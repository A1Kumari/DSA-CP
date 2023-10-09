class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string str;
        int n = words.size();
        
        for(int i=0; i<n; i++){
            str.push_back(words[i][0]);
        }
        
        return s == str;
    }
};
