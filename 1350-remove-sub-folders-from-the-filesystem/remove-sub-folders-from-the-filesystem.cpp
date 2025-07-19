#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // This function takes a list of folder paths and removes any subfolders
    // from the list since a subfolder is implicitly included when its parent
    // folder is included.
    vector<string> removeSubfolders(vector<string>& folders) {
        // Sort the folder list to ensure that subfolders follow their parents
        sort(folders.begin(), folders.end());

        // Initialize the answer list with the first (smallest) folder
        vector<string> filteredFolders = {folders[0]};

        // Iterate through the sorted folders starting from the second element
        for (int i = 1; i < folders.size(); ++i) {
            int parentSize = filteredFolders.back().size();
            int currentSize = folders[i].size();
          
            // Check if the current folder is a subfolder of the last parent folder
            // Subfolder check: the parent is a prefix and is followed by a '/' in the current folder
            if (parentSize >= currentSize || 
                !(filteredFolders.back() == folders[i].substr(0, parentSize) && folders[i][parentSize] == '/')) {
                // If the current folder is not a subfolder, add it to the answer list
                filteredFolders.emplace_back(folders[i]);
            }
        }

        // Return the list of filtered folders
        return filteredFolders;
    }
};