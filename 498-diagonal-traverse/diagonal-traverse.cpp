#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        std::vector<int> result;
        std::vector<int> diagonalElements;
      
        // Iterate over all possible diagonals in the matrix
        for (int diag = 0; diag < rows + columns - 1; ++diag) {
            // Initialize row index (i) and column index (j) for the start of the diagonal
            int i = diag < columns ? 0 : diag - columns + 1;
            int j = diag < columns ? diag : columns - 1;
          
            // Collect all elements in the current diagonal
            while (i < rows && j >= 0) {
                diagonalElements.push_back(matrix[i++][j--]);
            }
          
            // If the diagonal index is even, we need to reverse the diagonal elements
            // to maintain the "zigzag" diagonal order
            if (diag % 2 == 0) {
                std::reverse(diagonalElements.begin(), diagonalElements.end());
            }
          
            // Append the current diagonal's elements to the result vector
            for (int value : diagonalElements) {
                result.push_back(value);
            }
          
            // Clear the diagonal elements vector for the next diagonal
            diagonalElements.clear();
        }
      
        // Return the final vector with all elements in diagonal order
        return result;
    }
};