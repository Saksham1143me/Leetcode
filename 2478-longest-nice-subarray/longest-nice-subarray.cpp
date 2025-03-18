class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        int i = 0, j = 0, bitmask = 0, maxval = 1;
        int n = nums.size();
        
        while (j < n) {
            while ((bitmask & nums[j]) != 0) {
                bitmask ^= nums[i];
                i++;
            }
            bitmask |= nums[j];
            maxval = std::max(maxval, j - i + 1);
            j++;
        }
        return maxval;
    }
};
