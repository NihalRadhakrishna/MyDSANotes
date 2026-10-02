// LeetCode Problem: 138. Copy List with Random Pointer
// Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/


class Solution {
    public:
        // Approach 1: Interleave each copy with its original node.
        // The list temporarily becomes original -> copy -> original -> copy.
        Node* copyRandomList(Node* head) {            if (!head) return nullptr;
    
            Node* curr = head;
    
            // 1. Create copy nodes and insert after originals
            while (curr) {
                Node* copy = new Node(curr->val);
    
                copy->next = curr->next;
                curr->next = copy;
    
                curr = copy->next;
            }
    
            // 2. Set random pointers
            curr = head;
    
            while (curr) {
                Node* copy = curr->next;
    
                // The copy of curr->random is the node placed immediately
                // after curr->random, so its next pointer is that copy.
                if (curr->random)
                    copy->random = curr->random->next;
    
                curr = copy->next;
            }
    
            // 3. Separate the lists
            curr = head;
            Node* copyHead = head->next;
    
            while (curr) {
                Node* copy = curr->next;
    
                curr->next = copy->next;
    
                if (copy->next)
                    copy->next = copy->next->next;
    
                curr = curr->next;
            }
    
            return copyHead;
        }

        // Time complexity: O(n)
        // Space complexity: O(1), excluding the newly created list


        // Approach 2: Map each original node to its copy.
        // The first pass creates every copy. The second pass can then assign
        // next and random because both target nodes already exist in the map.
        Node* copyRandomListMap(Node* head) {
            if (!head) return nullptr;

            unordered_map<Node*, Node*> copies;
            Node* curr = head;

            while (curr) {
                copies[curr] = new Node(curr->val);
                curr = curr->next;
            }

            curr = head;

            while (curr) {
                Node* copy = copies[curr];

                if (curr->next)
                    copy->next = copies[curr->next];

                if (curr->random)
                    copy->random = copies[curr->random];

                curr = curr->next;
            }

            return copies[head];
        }

        // Time complexity: O(n)
        // Space complexity: O(n) for the map, excluding the newly created list
    };