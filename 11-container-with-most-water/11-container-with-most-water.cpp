class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer=INT_MIN;
        int left=0,right=height.size()-1;
        int area=0;
        while(left<right)
        {
            area=min(height[right],height[left])*(right-left);
            answer=max(answer,area);
            if(height[right]<=height[left]) right--;
            else
                left++;
            
        }
        return answer;
    }
};