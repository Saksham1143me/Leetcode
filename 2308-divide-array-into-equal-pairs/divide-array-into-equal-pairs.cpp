#include <unordered_map>
#include <vector>

class Solution {
public:
    bool divideArray(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto [key, value] : freq) {
            if (value % 2 != 0) return false;
        }
        return true;
    }
};
