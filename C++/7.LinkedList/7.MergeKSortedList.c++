// LeetCode Problem: 23. Merge k Sorted Lists
// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/


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
        // priority_queue is a max-heap by default. Returning a->val > b->val
        // gives the smaller node higher priority, so this becomes a min-heap.
        struct Compare{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };

        // Keep the current head of every list in the heap. The top is always
        // the smallest remaining node, so popping it builds the merged list.
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
            int n = lists.size();
            for(int i = 0; i<n; i++){
                if(lists[i] != NULL)
                    pq.push(lists[i]);
            }
            ListNode* curr = NULL;
            ListNode* head = NULL;
            ListNode* temp = NULL;
            while(!pq.empty()){
                temp = pq.top();
                pq.pop();
                if(!head){
                    head = temp;
                    curr = temp;
                }
                else{
                    curr->next = temp;
                    curr = curr->next;
                }
                
                // The next node of this list may now be the smallest remaining value.
                if(temp->next) pq.push(temp->next);
            }
            return head;
        }
    };


// Time complexity: O(N log k)
// Space complexity: O(k)
// Here, N is the total number of nodes and k is the number of lists.