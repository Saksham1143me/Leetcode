#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Use a set for quick lookup of banned numbers
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        int currentSum = 0;
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (bannedSet.find(i) == bannedSet.end()) {
                if (currentSum + i <= maxSum) {
                    currentSum += i;
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
