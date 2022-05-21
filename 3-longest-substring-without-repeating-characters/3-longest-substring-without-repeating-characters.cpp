class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> mapp;
        int res = 0;
        int start = 0;
        for(int end = 0; end < s.size(); end++){
            if(mapp.count(s[end])){
                start = max(start, mapp[s[end]]+1);
            }
            res = max(res, end - start + 1);
            mapp[s[end]] = end;
        }
        return res;
    }
        
    
};