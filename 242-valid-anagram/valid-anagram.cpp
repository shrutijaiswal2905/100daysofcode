class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        if (m1== m2){
            return true;
        }
        return false;
        
    }
};