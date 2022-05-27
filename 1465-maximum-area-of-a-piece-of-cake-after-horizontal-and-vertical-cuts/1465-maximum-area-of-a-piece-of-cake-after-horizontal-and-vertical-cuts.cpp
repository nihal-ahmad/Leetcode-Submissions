class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int x = horizontalCuts.size();
        int y = verticalCuts.size();
    int maxHeight = max(horizontalCuts[0]-0,h-horizontalCuts[x-1]);
        for(int i=1;i<x;i++)
        {int width =horizontalCuts[i]-horizontalCuts[i-1];
            maxHeight=max(width,maxHeight);
        }
        int maxWidth = max(verticalCuts[0]-0,w-verticalCuts[y-1]);
        for(int i=1;i<y;i++)
        {
           int width =verticalCuts[i]-verticalCuts[i-1];
            maxWidth=max(width,maxWidth);
        }
        long area = 1L*maxHeight*maxWidth;
      
        return (int)(area%1000000007);
    }
};