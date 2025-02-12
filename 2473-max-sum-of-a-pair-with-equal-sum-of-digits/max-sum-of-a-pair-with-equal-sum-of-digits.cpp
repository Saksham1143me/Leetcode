#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, pair<int, int>> mp;
        
        for (int num : nums) {
            int sum = digitSum(num);
            if (mp.find(sum) == mp.end()) {
                mp[sum] = {num, -1};
            } else {
                if (num > mp[sum].first) {
                    mp[sum].second = mp[sum].first;
                    mp[sum].first = num;
                } else if (num > mp[sum].second) {
                    mp[sum].second = num;
                }
            }
        }

        int maxSum = -1;
        for (auto it : mp) {
            if (it.second.second != -1) {
                maxSum = max(maxSum, it.second.first + it.second.second);
            }
        }
        return maxSum;
    }

private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
