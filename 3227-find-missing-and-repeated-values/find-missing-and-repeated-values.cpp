class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(); // n x n grid
        int total = n * n;   // Total elements = n^2
        vector<int> count(total + 1, 0); // Count array of size n^2 + 1
        long long sum = 0, tsum = (total * (total + 1)) / 2; // Sum from 1 to n^2
        int repeated, missing;

        // Traverse the grid and count occurrences
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                sum += val; // Add to total sum
                count[val]++;
                if (count[val] == 2) {
                    repeated = val; // If count becomes 2, it's the repeated number
                }
            }
        }

        // Missing number formula
        missing = tsum - (sum - repeated);

        return {repeated, missing};
    }
};
