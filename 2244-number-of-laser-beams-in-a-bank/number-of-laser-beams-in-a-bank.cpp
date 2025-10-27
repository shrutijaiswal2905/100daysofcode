class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;           // Total number of laser beams
        int previousDeviceCount = 0;  // Number of devices in the previous non-empty row
      
        // Iterate through each row in the bank
        for (const auto& row : bank) {
            // Count the number of security devices ('1's) in the current row
            int currentDeviceCount = count(row.begin(), row.end(), '1');
          
            // If current row has devices, calculate beams with previous row
            if (currentDeviceCount > 0) {
                // Add beams formed between current row and previous non-empty row
                // Each device in previous row connects to each device in current row
                totalBeams += previousDeviceCount * currentDeviceCount;
              
                // Update previous device count for next iteration
                previousDeviceCount = currentDeviceCount;
            }
        }
      
        return totalBeams;
    }
};