class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // Create an array to count occurrences of each remainder class modulo 'value'
        int remainderCount[value];
        memset(remainderCount, 0, sizeof(remainderCount));
      
        // Count how many numbers fall into each remainder class
        // Use ((x % value) + value) % value to handle negative numbers correctly
        for (int num : nums) {
            int remainder = ((num % value) + value) % value;
            ++remainderCount[remainder];
        }
      
        // Find the smallest non-negative integer that cannot be formed
        // by adding multiples of 'value' to elements in nums
        for (int i = 0; ; ++i) {
            int remainderClass = i % value;
          
            // If no number in this remainder class is available, return i
            if (remainderCount[remainderClass] == 0) {
                return i;
            }
          
            // Use one number from this remainder class
            --remainderCount[remainderClass];
        }
    }
};