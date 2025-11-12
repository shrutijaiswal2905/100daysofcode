class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Count the number of 1s in the array
        int countOnes = 0;
        for (int num : nums) {
            if (num == 1) countOnes++;
        }
        
        // If there are already 1s, we need (n - countOnes) operations
        // to convert all other elements to 1
        if (countOnes > 0) {
            return n - countOnes;
        }
        
        // Step 2: No 1s exist, so find the shortest subarray with GCD = 1
        int minLen = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                
                // If GCD becomes 1, we found a valid subarray
                if (g == 1) {
                    minLen = min(minLen, j - i);
                    break;
                }
            }
        }
        
        // If no subarray with GCD = 1 exists, it's impossible
        if (minLen == INT_MAX) {
            return -1;
        }
        
        // We need (minLen) operations to create first 1,
        // then (n - 1) operations to spread it to all elements
        return minLen + n - 1;
    }
};
