#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int num : nums) {
            if (num < k) pq.push(num);
        }

        int count = 0;

        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            count++;

            if (pq.empty()) break;

            int y = pq.top();
            pq.pop();
            long newValue = 2L * x + y;

            if (newValue < k) pq.push((int) newValue);
        }

        return count;
    }
};
