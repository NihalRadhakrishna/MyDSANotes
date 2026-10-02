// LeetCode Problem: 876. Middle of the Linked List
// Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/
// LeetCode Problem: 2095. Delete the Middle Node of a Linked List
// Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/


/*
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
*/


class Solution {
public:
    // Approach 1: Count the nodes, then move n / 2 steps.
    // For an even-sized list, this returns the second middle node.
    ListNode* middleNodeCounting(ListNode* head) {
        int count = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        curr = head;
        for (int i = 0; i < count / 2; i++) {
            curr = curr->next;
        }

        return curr;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)


    // Approach 2: Slow and fast pointers
    // Slow moves one node while fast moves two nodes. When fast reaches the
    // end, slow is at the middle. This also returns the second middle node.
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)


    // Delete the middle node using slow and fast pointers.
    // prev follows one node behind slow so it can bypass the middle node.
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
};
