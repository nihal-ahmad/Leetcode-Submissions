class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          int res = 0, maxLeng;
        for(int i=0; i<s.size(); i++){
            unordered_set<char> temp;
            maxLeng = 0;
            for(int j=i; j<s.size(); j++){
                if(!temp.count(s[j])){
                    maxLeng++;
                    temp.insert(s[j]);
                }else break;
                res = max(res, maxLeng);
            }
        }
        return res;
    }
        
    
};