class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int componentCount = 0;
      
        // Build adjacency list representation of the tree
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }
      
        // DFS function to traverse the tree and count valid components
        // Returns the sum of values in the subtree rooted at current node
        function<long long(int, int)> dfs = [&](int currentNode, int parentNode) -> long long {
            // Start with the value of current node
            long long subtreeSum = values[currentNode];
          
            // Traverse all children (neighbors except parent)
            for (int childNode : adjacencyList[currentNode]) {
                if (childNode != parentNode) {
                    // Add the sum from child's subtree
                    subtreeSum += dfs(childNode, currentNode);
                }
            }
          
            // If current subtree sum is divisible by k, it can form a separate component
            if (subtreeSum % k == 0) {
                componentCount++;
            }
          
            // Return the subtree sum for parent's calculation
            return subtreeSum;
        };
      
        // Start DFS from node 0 with no parent (-1)
        dfs(0, -1);
      
        return componentCount;
    }
};