// LeetCode Problem: 61. Rotate List
// Problem Link: https://leetcode.com/problems/rotate-list/


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
        // A right rotation by k moves the last k nodes to the front.
        // Find the new tail at position (length - k), detach the suffix,
        // and attach the old head to the end of that suffix.
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head || !head->next || k == 0) return head;
            int len = 0;
            ListNode* curr = head;
            while(curr){
                curr = curr->next;
                len++; 
            }

            // Rotating by the list length brings every node back to its place.
            k = k%len;
            if(k == 0){
                return head;
            }

            // Move to the new tail. For 1 -> 2 -> 3 -> 4 -> 5 and k = 2,
            // the new tail is 3 and the new head is 4.
            curr = head;
            for(int i = 1; i<len-k; i++){
                curr = curr->next;
            }
            ListNode* newHead = curr->next;
            curr->next = NULL;

            // Attach the original list after the rotated suffix.
            ListNode* temp = newHead;
            while(temp->next){
                temp=temp->next;
            }
            temp->next = head;
            return newHead;
        }
    };


// Time complexity: O(n)
// Space complexity: O(1)