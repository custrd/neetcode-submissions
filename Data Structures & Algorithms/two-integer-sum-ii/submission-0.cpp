class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0; i<n-1; i++){
            int lo = i+1, hi = n-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                int key = target - numbers[i];
                if(numbers[mid] == key) return {i+1, mid+1};
                else if(numbers[mid] < key) lo = mid+1;
                else hi = mid-1;
            }
        }
        return {1, 1};
    }
};
