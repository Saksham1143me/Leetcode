#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int num : nums) {
            pq.push(num);
        }

        int count = 0;
            while (pq.size() >= 2 && pq.top() < k) {
            long long n1 = pq.top(); pq.pop();
            long long n2 = pq.top(); pq.pop();
            long long newVal = n1 * 2 + n2;
            pq.push(newVal);
            count++;
        }
        if (pq.top() < k) return -1;

        return count;
    }
};
