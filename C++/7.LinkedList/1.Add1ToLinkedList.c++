/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

// Approach:
// Reverse the list so the least significant digit comes first, add one while
// propagating the carry, append a new node if a carry remains, and reverse the
// list again to restore the original digit order.
class Solution {
    public:
      // Iteratively reverse the linked list.
      Node* reverse(Node* head){
          Node* prev = NULL;
          Node* curr = head;
          Node* temp = head;
          while(curr){
              temp = curr;
              curr = curr->next;
              temp->next = prev;
              prev = temp;
              
          }
          return prev;
      }
      Node* addOne(Node* head) {
          // Reverse to begin addition from the units digit.
          Node* rev = reverse(head);
          int carry = 1;
          Node* temp = rev;
          Node* prev = NULL;

          // Continue only while a carry remains. Once carry becomes zero,
          // the remaining digits do not need to be changed.
          while(temp){
              int sm = temp->data + carry;
              temp->data = sm%10;
              carry = sm>=10 ? 1: 0;
              if(carry == 0) break;
              prev = temp;
              temp = temp->next;
          }

          // Numbers such as 999 produce an extra leading digit.
          if(carry == 1){
              prev->next = new Node(1);
          }

          // Restore the most-significant-digit-first order.
          Node* ans = reverse(rev);
          return ans;
      }
  };


// Time complexity: O(n)
// Space complexity: O(1) auxiliary space