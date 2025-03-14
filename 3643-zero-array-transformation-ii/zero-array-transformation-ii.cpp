class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        if (!canMakeZero(nums, queries, right)) return -1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeZero(nums, queries, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

private:
    bool canMakeZero(vector<int> nums, vector<vector<int>>& queries, int k) {
        int m = nums.size();
        vector<int> prefix(m + 1, 0);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            prefix[l] += val;
            if (r + 1 < m) prefix[r + 1] -= val;
        }

        int currVal = 0;
        for (int i = 0; i < m; i++) {
            currVal += prefix[i];
            if (currVal < nums[i]) return false;
        }
        return true;
    }
};
