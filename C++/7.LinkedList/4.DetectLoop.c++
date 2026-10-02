// LeetCode Problem: 141. Linked List Cycle
// Problem Link: https://leetcode.com/problems/linked-list-cycle/
// LeetCode Problem: 142. Linked List Cycle II
// Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/


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
    // Approach 1: Hashing
    // If a node is visited for a second time, the linked list contains a loop.
    bool hasCycleHashing(ListNode* head) {
        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.count(head)) {
                return true;
            }

            visited.insert(head);
            head = head->next;
        }

        return false;
    }

    // Time complexity: O(n)
    // Space complexity: O(n)


    // Approach 2: Floyd's cycle detection
    // Slow moves one step and fast moves two steps. If a loop exists, the
    // pointers must eventually meet inside it. Otherwise, fast reaches null.
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)


    // Find the first node of the loop.
    // After slow and fast meet, move one pointer back to head. Moving both
    // one step at a time makes them meet at the start of the loop.
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)


    // Approach 1: Count the nodes after finding the loop's starting node.
    int loopLength(ListNode* head) {
        ListNode* start = detectCycle(head);

        if (start == nullptr) {
            return 0;
        }

        int length = 1;
        ListNode* curr = start->next;

        while (curr != start) {
            length++;
            curr = curr->next;
        }

        return length;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)


    // Approach 2: Count directly from the meeting point.
    // After slow and fast meet inside the loop, keep moving one pointer until
    // it returns to the meeting point. That distance is the loop length.
    int loopLengthFromMeetingPoint(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                int length = 1;
                ListNode* curr = slow->next;

                while (curr != slow) {
                    length++;
                    curr = curr->next;
                }

                return length;
            }
        }

        return 0;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)


    // Break the loop by setting the node before the loop start to nullptr.
    void removeLoop(ListNode* head) {
        ListNode* start = detectCycle(head);

        if (start == nullptr) {
            return;
        }

        ListNode* curr = start;

        while (curr->next != start) {
            curr = curr->next;
        }

        curr->next = nullptr;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
};
