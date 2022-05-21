class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeIntervals;
        sort(intervals.begin(),intervals.end());
         pair<int,int> temp = {intervals[0][0],intervals[0][1]};
        for(int i=1;i<intervals.size();i++)
        {
           
            if(intervals[i][0]<=temp.second)
                temp.second = max(temp.second,intervals[i][1]);
            else
            {vector<int> t;
             t.push_back(temp.first);
             t.push_back(temp.second);
                mergeIntervals.push_back(t);
             
                temp.first = intervals[i][0];
                temp.second = intervals[i][1];
            }
            
        }
        vector<int> t;
        t.push_back(temp.first);
             t.push_back(temp.second);
                mergeIntervals.push_back(t);
        return mergeIntervals;
    }
};