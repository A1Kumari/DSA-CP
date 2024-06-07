class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n+1,0);
        if(n>=1){
            dp[1] = 1;
        }
        
        for(int i=2; i<= n; i++){
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};