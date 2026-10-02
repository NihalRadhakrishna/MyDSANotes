// LeetCode Problem: 148. Sort List
// Problem Link: https://leetcode.com/problems/sort-list/


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
    // Merge sort: split the list into two halves, sort each half, then merge.
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = getMiddle(head);
        ListNode* rightHead = mid->next;

        // Break the list so the left half ends at mid.
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left, right);
    }

    // Time complexity: O(n log n)
    // Space complexity: O(log n) for the recursive call stack

private:
    // Slow moves one step and fast moves two steps.
    // When fast reaches the end, slow is just before the second half.
    // For an even-sized list this returns the first middle node, so the
    // two halves differ in size by at most one.
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two already sorted lists by always attaching the smaller node.
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        curr->next = (left != nullptr) ? left : right;
        return dummy.next;
    }
};
