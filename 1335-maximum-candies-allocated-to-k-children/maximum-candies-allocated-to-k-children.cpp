class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int maxVal = 0;

        for (int candy : candies) {
            sum += candy;
            maxVal = max(maxVal, candy); // Find the maximum candy count in any pile
        }

        if (sum < k) return 0; // If total candies are less than children, return 0

        return binarySearch(candies, k, 1, maxVal);
    }

private:
    int binarySearch(vector<int>& candies, long long k, int left, int right) {
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;

            for (int candy : candies) {
                count += (candy / mid); // Number of children who can receive `mid` candies
            }

            if (count >= k) { // If we can distribute at least `k` portions
                ans = mid;
                left = mid + 1; // Try to increase the portion size
            } else {
                right = mid - 1; // Reduce portion size
            }
        }
        return ans;
    }
};
