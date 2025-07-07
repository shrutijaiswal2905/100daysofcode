class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp1;
        map<char,int> mp2;

        for(int i =0; i< ransomNote.size(); i++){
            mp1[ransomNote[i]]++;
        }
        for(int i =0; i< magazine.size(); i++){
            mp2[magazine[i]]++;
        }
        for (auto pair: mp1){
            char ch = pair.first;
            int needed = pair.second;
            if(mp2[ch] < needed){
                return false;
            }
        }
        return true;

    }
};