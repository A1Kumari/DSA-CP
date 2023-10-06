class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long closestSum = INT_MAX;  // Initialize closestSum with a large value
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                long long sum = static_cast<long long>(nums[i]) + nums[left] + nums[right];
                
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return static_cast<int>(closestSum);
    }
};
