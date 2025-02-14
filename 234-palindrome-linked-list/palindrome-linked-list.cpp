class Solution {
public:
    ListNode* left;

    bool isPalindrome(ListNode* head) {
        left = head;  // Left pointer initialized to the head
        return checkPalindrome(head);
    }

    bool checkPalindrome(ListNode* right) {
        if (right == nullptr) return true;
        bool isPal = checkPalindrome(right->next);
        if (!isPal) return false;
        if (left->val != right->val) return false;
        
        left = left->next;
        
        return true;
    }
};
