class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> frequency;
        for(auto i:arr)
            frequency[i]++;
      multiset<pair<int,int>> m;
        for(auto i:frequency)
            m.insert({i.second,i.first});
        int total=0;
        for(auto i:m)
        {
            if(k>=i.first) 
            {
                k-=i.first;
                total++;
                
            }
            else
                break;
        }
        return m.size()-total;
    }
};