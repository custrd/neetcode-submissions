class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // if(prices.size() == 1) return 0;
        int n = prices.size();
        int lo = 0, hi = 1, ans = 0, cur = 0;
        while(hi<=n-1){
            if(prices[hi]>prices[lo]){
                cur = prices[hi]-prices[lo];
                ans = max(ans, cur);
                hi++;
            }else{
                lo = hi;
                hi++;
                // cur = 0;
            }
        }
        return ans;
    }
};
