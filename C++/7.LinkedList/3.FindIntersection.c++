// LeetCode Problem: 160. Intersection of Two Linked Lists
// Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/


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
    // Store every node from list A, then find the first node in list B
    // that is already present in the set.
    ListNode* getIntersectionNodeHashing(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> nodes;

        while (headA != nullptr) {
            nodes.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if (nodes.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
    }

    // Time complexity: O(m + n)
    // Space complexity: O(m)


    // Approach 2: Align both lists by their lengths
    // Move the longer list ahead by the length difference, then move both
    // pointers together until they point to the same node.
    ListNode* getIntersectionNodeByLength(ListNode* headA, ListNode* headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        while (lengthA > lengthB) {
            headA = headA->next;
            lengthA--;
        }

        while (lengthB > lengthA) {
            headB = headB->next;
            lengthB--;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

    // Time complexity: O(m + n)
    // Space complexity: O(1)


    // Approach 3: Pointer switching
    // After reaching the end, each pointer starts at the other list's head.
    // Both pointers then travel the same total distance (m + n), so they meet
    // at the intersection or both become nullptr when no intersection exists.
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;

        while (pointerA != pointerB) {
            pointerA = (pointerA == nullptr) ? headB : pointerA->next;
            pointerB = (pointerB == nullptr) ? headA : pointerB->next;
        }

        return pointerA;
    }

    // Time complexity: O(m + n)
    // Space complexity: O(1)

private:
    int getLength(ListNode* head) {
        int length = 0;

        while (head != nullptr) {
            length++;
            head = head->next;
        }

        return length;
    }
};
