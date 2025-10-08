class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort potions array in ascending order for binary search
        sort(potions.begin(), potions.end());
      
        // Result vector to store count of successful pairs for each spell
        vector<int> result;
      
        // Get the total number of potions
        int potionCount = potions.size();
      
        // Iterate through each spell
        for (int& spellStrength : spells) {
            // Calculate minimum potion strength needed for this spell
            // Using ceiling division: (success + spellStrength - 1) / spellStrength
            // to avoid floating point arithmetic issues
            long long minPotionStrength = (success + spellStrength - 1) / spellStrength;
          
            // Find the first potion that meets the minimum strength requirement
            // using binary search (lower_bound)
            int firstValidIndex = lower_bound(potions.begin(), potions.end(), minPotionStrength) - potions.begin();
          
            // Calculate number of successful pairs (all potions from firstValidIndex to end)
            int successfulPairCount = potionCount - firstValidIndex;
          
            // Add the count to result vector
            result.push_back(successfulPairCount);
        }
      
        return result;
    }
};
