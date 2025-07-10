class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }
        for( auto& pair : mp){
            if(pair.second> n/2){
                return pair.first;
            }
        }  
        return -1;  
    }
};