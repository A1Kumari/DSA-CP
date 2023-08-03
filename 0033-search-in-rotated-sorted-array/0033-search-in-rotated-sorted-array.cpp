class Solution {
public:
    int rotatedSearch(vector<int>& nums, int target, int left, int right){
        
        while(left<=right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] >= nums[left]){
                if(target<nums[mid] && target>=nums[left]){
                   return rotatedSearch(nums, target,left, mid-1);
                }else{
                    return rotatedSearch(nums, target, mid+1, right);
                }
            } else{
                if (target>nums[mid] && target<=nums[right]){
                    return rotatedSearch(nums, target,mid+1, right);
                }else{
                    return rotatedSearch(nums, target, left, mid-1);
                }
            }
       }
        return -1;
    }
    int search(vector<int>& nums, int target) {
      
        int n = nums.size();
        int left = 0;
        int right = n-1;
        return rotatedSearch(nums, target, left, right);
    }
};