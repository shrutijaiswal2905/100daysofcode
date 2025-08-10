class Solution {
public:
    // This function checks if it's possible to reorder digits of 'n' to make it a power of two
    bool reorderedPowerOf2(int n) {
        // Convert the original number 'n' to its digits count array
        vector<int> originalDigitsCount = countDigits(n);
        // Loop through the powers of 2 within the int range
        for (int i = 1; i <= 1e9; i <<= 1) {
            // Compare the digits count of the current power of 2 with the original number
            if (originalDigitsCount == countDigits(i))
                return true;
        }
        return false;
    }

    // Helper function to count the digits of a number and return them as a vector
    vector<int> countDigits(int n) {
        vector<int> digitCount(10, 0);
        while (n != 0) {
            // Increase the count of the rightmost digit
            digitCount[n % 10]++;
            // Remove the rightmost digit
            n /= 10;
        }
        return digitCount;
    }
};