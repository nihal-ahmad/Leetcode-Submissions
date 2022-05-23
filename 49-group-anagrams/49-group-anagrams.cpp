class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            string x=it;
            sort(it.begin(),it.end());
            mp[it].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};