class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==1) return 0;
        int n = height.size();
        int ans = 0;
        vector<int> left(n,0), right(n,0);
        int left_max=0, right_max=0;
        for(int i=0; i<n; i++){
            left_max = max(left_max, height[i]);
            left[i] = left_max;
        }
        for(int i=n-1; i>=0; i--){
            right_max = max(right_max, height[i]);
            right[i] = right_max;
        }
        //stored max left and right max for each and every element to determine the min wall
        for(int i=1; i<n-1; i++){
            int num = min(left[i-1], right[i+1])-height[i];
            if(num>0) ans+=num;
        }
        return ans;
    }
};
