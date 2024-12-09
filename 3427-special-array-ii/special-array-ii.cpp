#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<bool> ans(m);
        vector<int> isAlternating(n, 0);
        for (int i = 1; i < n; i++) {
            if ((nums[i] % 2) == (nums[i - 1] % 2)) {
                isAlternating[i] = isAlternating[i - 1] + 1;
            } else {
                isAlternating[i] = isAlternating[i - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (start == end) {
                ans[i] = true;
                continue;
            }
            if (isAlternating[end] == isAlternating[start]) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }

        return ans;
    }
};
