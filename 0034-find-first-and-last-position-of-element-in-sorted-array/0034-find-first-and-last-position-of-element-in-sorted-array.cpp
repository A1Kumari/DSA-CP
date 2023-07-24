class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        
        int left =0;
        int right = n-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
           if (nums[mid] == target) {
                // Search for the starting position of target
                int start = mid;
                while (start >= 0 && nums[start] == target) {
                    res[0] = start;
                    start--;
                }
                
                // Search for the ending position of target
                int end = mid;
                while (end < n && nums[end] == target) {
                    res[1] = end;
                    end++;
                }
                
                break;
            } 
            else if( nums[mid] <= target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return res;
    }
};