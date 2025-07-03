class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        
        // Keep performing operations until we have at least k characters
        while (word.length() < k) {
            string generated = "";
            
            // Transform each character to its next character
            for (char c : word) {
                if (c == 'z') {
                    generated += 'a';  // 'z' wraps around to 'a'
                } else {
                    generated += (c + 1);  // next character in alphabet
                }
            }
            
            // Append the generated string to the original word
            word += generated;
        }
        
        // Return the k-th character (1-indexed, so k-1 for 0-indexed)
        return word[k - 1];
    }
};