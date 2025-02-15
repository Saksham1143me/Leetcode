class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (backtrack(i * i, i)) {
                sum += i * i;
            }
        }
        return sum;
    }

private:
    bool backtrack(int num, int target, int sum = 0) {
        if (num == 0) return sum == target;

        int curr = 0;
        int power = 1;

        while (num / power > 0) {  // Ensure power does not exceed num
            curr = num % (power * 10);  // Extract last `k` digits
            if (sum + curr > target) break;  // Prune invalid branches
            if (backtrack(num / (power * 10), target, sum + curr)) {
                return true;
            }
            power *= 10;  // Move to the next partition
        }

        return false;
    }
};
