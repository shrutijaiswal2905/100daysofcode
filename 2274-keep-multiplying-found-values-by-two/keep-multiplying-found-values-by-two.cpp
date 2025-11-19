class Solution {
public:
    int findFinalValue(vector<int>& A, int n) {
        set<int> s(begin(A), end(A));
        while (s.count(n)) n *= 2;
        return n;
    }
};