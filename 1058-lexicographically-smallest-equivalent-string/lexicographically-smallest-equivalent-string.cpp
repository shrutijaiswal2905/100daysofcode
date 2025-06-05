class Solution {
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        // Always attach the higher lex character to the lower one
        if (px == py) return;
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        // Initialize each character as its own parent
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        // Union equivalent characters
        for (int i = 0; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        // Build the result using the smallest lex representative
        string result = "";
        for (char c : baseStr) {
            result += char(find(c - 'a') + 'a');
        }

        return result;
    }
};
