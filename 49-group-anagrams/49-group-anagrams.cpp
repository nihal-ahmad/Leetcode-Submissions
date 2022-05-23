class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<map<char,int>,vector<string>> mp;                                                   
        for(auto it:strs){
           map<char,int> tempMap;
            vector<string> tempList;
            for(auto x:it)
                tempMap[x]++;
            auto itr = mp.find(tempMap);
            if(itr!=mp.end())
            itr->second.push_back(it);
            else
            {
                tempList.push_back(it);
                mp[tempMap] = tempList;
            }
            
        }
        vector<vector<string>>ans;
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};