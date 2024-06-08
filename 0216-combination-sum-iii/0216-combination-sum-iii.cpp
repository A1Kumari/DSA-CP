class Solution {
public:
    void backtrack(int k, int n, int start, vector<int>& current, vector<vector<int>>& res){
        if(current.size()==k && n==0){
            res.push_back(current);
            return;
        }

        if(current.size() > k || n<0){
            return;
        }

        for(int i=start; i<=9; i++){
            current.push_back(i);
            backtrack(k, n-i, i+1, current, res);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(k, n, 1, current, res);
        return res;
    }
};