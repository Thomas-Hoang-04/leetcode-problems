/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        while (head) {
            ListNode* memo = head->next;
            head->next = temp;
            temp = head;
            head = memo;
        }
        return temp;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        while (right) {
            left = left->next;
            right = right->next;
            if (right) right = right->next;
        }
        right = reverseList(left);
        left = head;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        } 
        return true;
    }
};