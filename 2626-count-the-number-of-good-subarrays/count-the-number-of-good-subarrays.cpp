class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long res = 0;
        long long pair = 0;
        int i = 0, n = nums.size();

        for (int j = 0; j < n; ++j) {
            pair += freq[nums[j]];
            freq[nums[j]]++;

            while (pair >= k) {
                res += (n - j);
                freq[nums[i]]--;
                pair -= freq[nums[i]];
                i++;
            }
        }
        return res;
    }
};
