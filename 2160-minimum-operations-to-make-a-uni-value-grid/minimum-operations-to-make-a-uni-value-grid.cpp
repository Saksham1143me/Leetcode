class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size();
        int n = grid[0].size();
        int mod = grid[0][0] % x;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != mod) {
                    return -1; 
                }
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];

        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
