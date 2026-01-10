class Solution {
public:
    int helper(int i, int j, int n1, int n2, const string &s1, const string &s2, vector<vector<int>> &dp)
    {
        if (i == n1) 
        {
            int sum = 0;
            for (int k = j; k < n2; k++) sum += s2[k];
            return sum;
        }
        if (j == n2) 
        {
            int sum = 0;
            for (int k = i; k < n1; k++) sum += s1[k];
            return sum;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j])
        {
            return dp[i][j] = helper(i+1, j+1, n1, n2, s1, s2, dp);
        }

        else
        {
            int val1 = (int)s1[i] + helper(i+1, j, n1, n2, s1, s2, dp);
            int val2 = (int)s2[j] + helper(i, j+1, n1, n2, s1, s2, dp);

            return dp[i][j] = min(val1, val2);        
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return helper(0, 0, n1, n2, s1, s2, dp);
    }
};