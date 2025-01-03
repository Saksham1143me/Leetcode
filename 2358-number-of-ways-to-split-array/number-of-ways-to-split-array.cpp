class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totSum = 0;  // Use long long
        int count = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }
        long long sum = 0;  // Use long long
        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            if (sum >= (totSum - sum)) {
                count += 1;
            }
        }
        return count;
    }
};
