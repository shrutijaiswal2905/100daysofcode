class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums){
            count[num]++;
            if (count[num] > 1){
                return true;
            }
        }
        return false;
    }
};