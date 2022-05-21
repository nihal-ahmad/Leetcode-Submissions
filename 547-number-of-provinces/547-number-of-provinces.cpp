class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int answer=0,n=isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {answer++;
                dfs(i,n,isConnected,visited);
            }
        }
        return answer;
        
    }
    void dfs(int sourse,int n,vector<vector<int>>& isConnected,vector<bool> &visited)
    {
        visited[sourse] = true;
        vector<int> adj;
        for(int i=0;i<n;i++)
        {
            int x = isConnected[sourse][i];
            if(x==1)
                adj.push_back(i);
        }
        for(auto i:adj)
        {
            if(!visited[i])
                dfs(i,n,isConnected,visited);
        }
    }
};