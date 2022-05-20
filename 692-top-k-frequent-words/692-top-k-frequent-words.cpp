class Solution {
public:
      struct comp
    {
        bool operator()(const pair<int,string> &a,const pair<int,string> &b)
        {
            if(a.first==b.first)
                return a.second>b.second;
        
            return a.first<b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
       vector<string> ans;
        
        unordered_map<string,int> f;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> q;
        int i,n=words.size();
        
        for(i=0;i<n;i++)
            f[words[i]]++;
        
        for(auto it:f)
            q.push({it.second,it.first});
        
        while(k--)
        {
            string s=q.top().second;
            q.pop();
            
            ans.push_back(s);
        }
        
        return ans;
        
    }
};