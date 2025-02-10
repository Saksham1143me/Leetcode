#include <map>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mp;
        while (head != NULL) {
            if (mp.find(head) != mp.end()) {
                return head;
            }
            mp[head] = 1;
            head = head->next;
        }
        return NULL;
    }
};
