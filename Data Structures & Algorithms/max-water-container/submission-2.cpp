class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int start = 0, end = n-1;
        while (start<=end){
            int cur = min(heights[start],heights[end]) * (end-start);
            ans = max(cur, ans);
            if(heights[start] < heights[end]) start++;
            else end--;
        }
        return ans;
    }
};
