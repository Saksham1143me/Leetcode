class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][n - 1] == target) {
                return true;
            } 
            else if (matrix[i][n - 1] > target) {
                if (binarySearch(matrix[i], target)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool binarySearch(vector<int>& row, int target) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == target) {
                return true;
            } else if (row[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
