class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count; // Stores frequency of fruit types in current window
        int l = 0, total = 0, res = 0;

        for (int r = 0; r < fruits.size(); r++) {
            count[fruits[r]]++; // Add current fruit to map
            total++;

            // If more than 2 fruit types, shrink window from left
            while (count.size() > 2) {
                int f = fruits[l];
                count[f]--;
                total--;
				// Remove fruit type if count is 0
                if (count[f] == 0) count.erase(f); 
                l++;
            }

			// Update maximum fruits collected
            res = max(res, total); 
        }

        return res;
    }
};