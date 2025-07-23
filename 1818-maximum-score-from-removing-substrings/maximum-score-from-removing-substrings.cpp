class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper function to remove all instances of a target substring
        // and return the points gained
        auto removeAndCount = [](string& str, const string& target, int points) -> int {
            int totalPoints = 0;
            string result;
            
            for (char c : str) {
                result.push_back(c);
                
                // Check if we can form the target substring
                if (result.length() >= 2 && 
                    result.substr(result.length() - 2) == target) {
                    // Remove the last 2 characters (the target substring)
                    result.pop_back();
                    result.pop_back();
                    totalPoints += points;
                }
            }
            
            str = result;
            return totalPoints;
        };
        
        int totalScore = 0;
        
        // Prioritize removing the substring that gives more points
        if (x >= y) {
            // Remove "ab" first, then "ba"
            totalScore += removeAndCount(s, "ab", x);
            totalScore += removeAndCount(s, "ba", y);
        } else {
            // Remove "ba" first, then "ab"
            totalScore += removeAndCount(s, "ba", y);
            totalScore += removeAndCount(s, "ab", x);
        }
        
        return totalScore;
    }
};