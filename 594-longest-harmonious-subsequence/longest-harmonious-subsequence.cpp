#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> frequencyMap; // Map to keep track of the frequency of each number in nums

        // Count the frequency of each number in the given nums array
        for (int num : nums) {
            ++frequencyMap[num]; // Increment the count for the number
        }

        int longestHarmoniousSequence = 0; // Variable to hold the length of the longest harmonious sequence

        // Iterate through the numbers in the array to find the longest harmonious sequence
        for (auto& [num, count] : frequencyMap) {
            // Check if there is a number in the map which is exactly one more than the current number
            if (frequencyMap.count(num + 1)) {
                // If found, update the longestHarmoniousSequence with the larger value between the previous
                // longest and the total count of the current number and the number that is one more.
                longestHarmoniousSequence = std::max(longestHarmoniousSequence, count + frequencyMap[num + 1]);
            }
        }

        // Return the length of the longest harmonious sequence found
        return longestHarmoniousSequence;
    }
};