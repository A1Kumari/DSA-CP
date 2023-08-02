class Solution {
public:
   vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int first = 0;
        int second = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp; 
       
        while(first < n && second < m){
            if (nums1[first] < nums2[second]) {
                temp.push_back(nums1[first]);
                first++;
            } else {
                temp.push_back(nums2[second]);
                second++;
            }
        }
       while( first < n){
           temp.push_back(nums1[first]);
           first++;
       }
       while(second < m){
           temp.push_back(nums2[second]);
           second++;
       }
       return temp;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedarr = merge(nums1, nums2);
        int n = mergedarr.size();
        
        int mid = n/2;
        
        if (n % 2 == 0) { // Even
            return (mergedarr[mid - 1] + mergedarr[mid]) / 2.0;
        } else {
            return mergedarr[mid];
        }
    }
};