class Solution {
public:
    int bs(vector<int>&nums, int low, int high, int target){
        if(low> high) return -1;
        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) {
            return bs(nums, mid+1, high, target);
        }
        return bs(nums, low, high-1, target);
    }
    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
        
    }
};